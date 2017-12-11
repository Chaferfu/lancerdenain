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

Scene::Scene(Point c, Ecran e, Source s, Couleur coul, vector<Sphere> v)
{
	camera = c;
	ecran = e;
	source = s;
	background = coul;
	spheres = v;
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
	//char line[1000];
	string str;

	passerCommentaires(stream);


	//creation camera

	float x, y, z, radius, reflx;
	int res, r, g, b;

	getline(stream, str);
	istringstream iss(str);
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug" << endl;
	}
	
	Point cam = Point(x, y, z);

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug" << endl;
	}

	Point pointTL(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug" << endl;
	}

	Point pointTR(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z))
	{
		cout << "hmmm ça bug" << endl;
	}

	Point pointBT(x,y,z);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> res))
	{
		cout << "hmmm ça bug" << endl;
	}

	Ecran e(pointTL,pointTR,pointBT,res);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> r >> g >> b))
	{
		cout << "hmmm ça bug" << endl;
	}

	Couleur bg(r,g,b);

	passerBlancs(stream);
	passerCommentaires(stream);

	getline(stream, str);
	iss = (istringstream(str));
	if(!(iss >> x >> y >> z >> r >> g >> b))
	{
		cout << "hmmm ça bug" << endl;
	}

	Source(Point(x,y,z), Couleur(r,g,b));

	passerBlancs(stream);
	passerCommentaires(stream);

	vector<Sphere> v;

	while(getline(stream, str))
	{
		istringstream iss(str);

		string type;

		if(!(iss >> type >> centerX >> centerY >> centerZ >> r >> colorR >> colorG >> colorB >> reflx))
		{
			cout << "hmmm ça bug" << endl;
			break;
		}

		if(!strcmp(type.c_str(), "sphere:"))
		{
			Sphere s(centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx);
			v.push_back(s);
		}
		else
		{
			cout << "c'est pas une shere mon gars" << endl;
		}

	}

	
	return Scene(cam, e, s, bg, v);
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
	cout << s.getCam() << endl;

	//c.testParsing();
	return 0;
}
