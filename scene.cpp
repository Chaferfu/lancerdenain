#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>			 
#include <sstream>
#include "couleur.hpp"
#include "point.hpp"
#include "rayon.hpp"
#include "sphere.hpp"
#include "ecran.hpp"
#include "source.hpp"
#include "scene.hpp"
using namespace std;

Scene::Scene(){
	
}

Scene::Scene(Point c, Ecran e, Source s)
{
	camera = c;
	ecran = e;
	source = s;
}

void Scene::addSphere(const Sphere s)
{
	spheres.push_back(s);
}

Rayon Scene::genererRayon(Point p){
	return Rayon(camera, p);
}


Scene parse()
{

	ifstream stream("In.txt", ifstream::in);
	char line[1000];

	passerCommentaires(stream);


	//creation camera

	float x, y, z;
	stream.getline(line, 5, ' ');
	x = atof(line);
	stream.getline(line, 5, ' ');
	y = atof(line);
	stream.getline(line, 5, '\n');
	z = atof(line);
	
	Point cam = Point(x, y, z);
/*
	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	stream.getline(line, 5, ' ');
	scene.getEcran().getTopLeft().setX(atof(line));
	stream.getline(line, 5, ' ');
	scene.getEcran().getTopLeft().setY(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getEcran().getTopLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getEcran().getTopRight().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getEcran().getTopRight().setY(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getEcran().getTopRight().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getEcran().getBottomLeft().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getEcran().getBottomLeft().setY(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getEcran().getBottomLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, '\n');
	scene.getEcran().setResolution(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getBackground().setR(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getBackground().setG(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getBackground().setB(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getSource().getPos().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getSource().getPos().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getSource().getPos().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getSource().getCouleur().setR(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getSource().getCouleur().setG(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getSource().getCouleur().setB(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	string line2(line);

	while(getline(stream, line2))
	{
		istringstream iss(line2);

		string type;
		int centerX, centerY, centerZ, r, colorR, colorG, colorB;
		float reflx;

		if(!(iss >> type >> centerX >> centerY >> centerZ >> r >> colorR >> colorG >> colorB >> reflx))
		{
			cout << "hmmm ça bug" << endl;
			break;
		}

		if(!strcmp(type.c_str(), "sphere:"))
		{
			Sphere s(centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx);
			scene.getSpheres().push_back(s);
		}
		else
		{
			cout << "c'est pas une shere mon gars" << endl;
		}

	}

	while(getline(stream, line))
	{
		istringstream iss(line);

		string type;
		int centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx;

		if(!(iss >> type >> centerX >> centerY >> centerZ >> r >> colorR >> colorG >> colorB >> reflx))
		{
			cout << "hmmm ça bug" << endl;
			break;
		}

		if(!strcmp(type, "sphere"))
		{
			Sphere s(centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx);
			scene.spheres.push_back(s);
		}
		else
		{
			cout << "c'est pas une shere mon gars" << endl;
		}

	}
*/Ecran e ; Source s;
	return Scene(cam, e, s);
}


/*
void testParsing()
{
	parse();
	cout << getScene().getCam() << endl;

}*/

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

int main()
{
	Scene s = parse();
	cout << s.getCam().getX() << endl;
	cout << s.getCam().getY() << endl;
	cout << s.getCam().getZ() << endl;

	//c.testParsing();
	return 0;
}
