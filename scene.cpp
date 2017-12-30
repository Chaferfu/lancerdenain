#include "scene.hpp"
using namespace std;

Scene::Scene(){}

Scene::Scene(const Point c, const Ecran& e, const PointColore s, const Couleur coul, const vector<Sphere> v, const vector<Triangle> t){
	camera = c;
	ecran = e;
	source = s;
	background = coul;
	spheres = v;
	triangles = t;
}

void Scene::addSphere(const Sphere s){
	spheres.push_back(s);
}

float Scene::calculerAngle(PointColore p){
	Point vNormale = spheres.at(idCourant).getCentre() - p; //normale entrante ??
	Point vRayon = source - p;

	float produit = vNormale.scalaire(vRayon);

	return acos(produit/(vNormale.norme()*vRayon.norme())) - M_PI;
}


/* Renvoie le point d'intersection entre un rayon et l'objet le plus 
 * proche de la caméra s'il existe, un point aux coordonnées infinies 
 * sinon.
 */
PointColore Scene::getIntersection(Rayon r){
	float a, b, c; // Coefficients du polynome d'ordre 2
	float sol1, sol2;
	float delta, t = numeric_limits<float>::infinity();
	Couleur coul = background;
	int i = 0;

	idCourant = -1;

	for(Sphere s : spheres){
		// Calcul des coefficients du polynome
		a = pow(r.getDirection().getX(), 2) + pow(r.getDirection().getY(), 2) + pow(r.getDirection().getZ(), 2);
		b = 2.0f*(r.getOrigine().getX() - s.getCentre().getX())*r.getDirection().getX() + 2.0f*(r.getOrigine().getY() - s.getCentre().getY())*r.getDirection().getY() + 2.0f*(r.getOrigine().getZ() - s.getCentre().getZ())*r.getDirection().getZ();
		c = pow((r.getOrigine().getX() - s.getCentre().getX()), 2) + pow((r.getOrigine().getY() - s.getCentre().getY()), 2) + pow((r.getOrigine().getZ() - s.getCentre().getZ()), 2) - pow(s.getRayon(), 2);

		// Calcul du discriminant
		delta = pow(b, 2) - 4.0f*a*c;

		sol1 = (-b-sqrt(delta))/(2*a);
		sol2 = (-b+sqrt(delta))/(2*a);

		//Calcul des racines
		if(delta >= 0.0f && (sol1 >0 || sol2 > 0))
		{
			
			if (sol1 < t)
			{
				t = sol1;
			}
			if (sol2 < t)
			{
				t = sol2;
			}

			coul = s.getCouleur();
			idCourant = i;
		}

		i++;
	}

	return PointColore(r.getOrigine().getX() + t*r.getDirection().getX(), r.getOrigine().getY() + t*r.getDirection().getY(), r.getOrigine().getZ() + t*r.getDirection().getZ(), coul);
}


/*Renvoie le rayon reflechi sur le premier objet touché 
 *ou le rayon incident si aucun objet n'est touché
 */
Rayon Scene::rayonReflechi(const Rayon incident)
{
	PointColore intersection = getIntersection(incident);
	if(idCourant != -1)
	{
		Point normale = spheres.at(idCourant).normale(intersection);
		Point directionUnitaireIncident = incident.getDirection()/incident.getDirection().norme();
		//cout << "incident : " << directionUnitaireIncident << "normale " << normale.getDirection() << endl;

		Point directionReflechi = directionUnitaireIncident - 2*(directionUnitaireIncident.scalaire(normale))*normale;

		Rayon reflechi(intersection + 1.f*directionReflechi, intersection + 2.0f*directionReflechi);
		//cout << "to return ::::: "  << intersection << " dir :" << directionReflechi << endl;
		return reflechi;
	}
	else
	{
		cout << "j'ai pas touché de boule :(" << endl;
		return incident;
	}
}


void Scene::ecrirePPM(){
	try{
		ofstream fichier("image.ppm", ios::out | ios::trunc);

		fichier << "P3" << endl;
		fichier << ecran.getReso() << " " << ecran.getResolutionVerticale() << endl;
		fichier << "255" << endl;

		// A modifier quand on aura rempli le tableau de pixels
		for(unsigned int i = 0; i < ecran.getResolutionVerticale(); i++){
			for(unsigned int j = 0; j < ecran.getReso(); j++)
				fichier << ecran.getPixels()[i][j] << endl;
		}

		fichier.close();
	} catch(exception const& e){
		cerr << "Erreur : " << e.what() << endl;
	}

	cout << "jveux pas mourir" << endl;
}

/* Renvoie vrai si le point passe en parametre recoit la lumiere de la 
 * source, faux sinon.
 */
bool Scene::estVisible(PointColore p){
	int prec = idCourant;
	PointColore p2 = getIntersection(Rayon(source, p));
	if(idCourant == -1 || (((Point)p2).distance((Point)source) - ((Point)p).distance((Point)source) < 0.005f && idCourant == prec))
		return true;
	return false;
}

void Scene::rayTracing(){
	PointColore pc, pcref;
	Rayon r, ref;
	float reflx;

	//#pragma omp parallel for
	for(unsigned int i = 0; i < ecran.getResolutionVerticale(); i++){
		for(unsigned int j = 0; j < ecran.getReso(); j++){
			r = Rayon(camera, ecran.getPixel(i*ecran.getReso()+j));
			pc = getIntersection(r);
			if(idCourant != -1) // Si le rayon a touché un objet
			{	
				reflx = spheres.at(idCourant).getReflex();
				ecran.getPixels()[i][j].calculerCouleur(estVisible(pc), calculerAngle(pc) , pc.getCouleur(), source.getCouleur());
					
				//reflexion speculaire
				ref = rayonReflechi(r);
				pcref = getIntersection(ref);
				ecran.getPixels()[i][j].calculerCouleurReflexion(pcref.getCouleur(), reflx);
			}
			else
				ecran.getPixels()[i][j] = background;
		}
	}
}

Scene parse(char* input){
	ifstream stream(input, ifstream::in);
	string str;

	passerCommentaires(stream);


	//creation camera

	float x, y, z, radius, reflx;
	int res, r, g, b;

	getline(stream, str);
	istringstream iss(str);
	if(!(iss >> x >> y >> z)){
		cout << "hmmm ça bug 1" << endl;
	}
	
	Point cam = Point(x, y, z);

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug 2" << endl;
	}

	Point pointTL(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug 3" << endl;
	}

	Point pointTR(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug 4" << endl;
	}

	Point pointBT(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> res))
	{
		cout << "hmmm ça bug 5" << endl;
	}

	Ecran e(res, pointTL,pointTR,pointBT);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> r >> g >> b))
	{
		cout << "hmmm ça bug 6" << endl;
	}

	Couleur bg(r,g,b);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z >> r >> g >> b))
	{
		cout << "hmmm ça bug 7" << endl;
	}

	PointColore s = PointColore(x,y,z, Couleur(r, g, b));

	passerBlancs(stream);
	passerCommentaires(stream);

	vector<Sphere> v;
	string type;

	while(getline(stream, str))
	{
		istringstream iss(str);


		if(!(iss >> type >> x >> y >> z >> radius >> r >> g >> b >> reflx))
		{
			cout << "hmmm ça bug" << endl;
			break;
		}

		if(!strcmp(type.c_str(), "sphere:"))
		{
			Sphere s(x, y, z, radius, r, g, b, reflx);
			v.push_back(s);
		}
		else
		{
			cout << "c'est pas une shere mon gars" << endl;
		}

	}

	cout << "parse : je n'ai plus peur de la mort" << endl;

	//TODO fermer le fichier : en fait c'est bon RAII
	stream.close(); //pas sur que ça soit necessaire ( ça se fait dans le destructeur du stream normalement)
	return Scene(cam, e, s, bg, v, vector<Triangle>());
}

void testParsing(char* input)
{
	Scene s = parse(input);
	cout << s.getCam() << endl;
	cout << s.getEcran() << endl;
	cout << "back :" << s.getBackground() << endl;
	cout << s.getSource() << endl;
	for(Sphere sp : s.getSpheres())
	{
		cout << sp << endl;
	}
}

void passerCommentaires(ifstream &stream)
{
	while(stream.peek() == '#') stream.ignore(256,'\n');
}

void passerBlancs(ifstream &stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}

ostream& operator<<( ostream &flux,const Ecran & e )
{
	e.afficher(flux);
    return flux;
}

ostream& operator<<( ostream &flux, Point const& p )
{
	p.afficher(flux);
    return flux;
}

ostream& operator<<( std::ostream &flux,const PointColore & s )
{
	s.afficher(flux);
	return flux;
}

ostream& operator<<( std::ostream &flux,const Couleur & c )
{
	c.afficher(flux);
	return flux;
}

ostream& operator<<( std::ostream &flux,const Sphere & s )
{
	s.afficher(flux);
	return flux;
}

void testOpPoints()
{
	Point p(1,2,3);
	Point p2(2,3,4);

	Point p3 = p + p2;
	cout << p3 << endl;
	p3 *= 2;
	cout << p3 << endl;

}

int main(int argc, char* argv[])
{
	if (argc == 0) cout << "il faut mettre le fichier d'entree en argument" << endl;

	Scene s = parse(argv[1]);
	
	s.rayTracing();

	s.ecrirePPM();

	return 0;
}
