#include "couleur.hpp"
#include "point.hpp"
#include "rayon.hpp"
#include "sphere.hpp"
#include "ecran.hpp"
#include "source.hpp"
#include "scene.hpp"
#include <iostream>
#include <fstream>
#include "controleur.hpp"
#include <fstream> 			 
#include <string.h>
#include <sstream>
using namespace std;


Controleur::Controleur(const Scene s)
{
	scene = s;
}

int main()
{
	
	return 0;
}

void Controleur::parse()
{

	ifstream stream("In.txt", ifstream::in);
	char* line = NULL;

	passerCommentaires(stream);


	//creation camera

	stream.getline(line, 5, ' ');
	scene.getCam().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getCam().setY(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getCam().setZ(atoi(line));
	

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	stream.getline(line, 5, ' ');
	scene.getEcran().getTopLeft().setX(atoi(line));
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
		int centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx;

		if(!(iss >> type >> centerX >> centerY >> centerZ >> r >> colorR >> colorG >> colorB >> reflx))
		{
			cout << "hmmm ça bug" << endl;
			break;
		}

		if(!strcmp(type.c_str(), "sphere"))
		{
			Sphere s(centerX, centerY, centerZ, r, colorR, colorG, colorB, reflx);
			scene.getSpheres().push_back(s);
		}
		else
		{
			cout << "c'est pas une shere mon gars" << endl;
		}

	}

	/*while(getline(stream, line))
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

	}*/
}

void Controleur::passerCommentaires(ifstream &stream)
{
	while(stream.peek() == '#') stream.ignore(256,'\n');

}

void Controleur::passerBlancs(ifstream &stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}
