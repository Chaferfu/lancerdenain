#include "couleur.hpp"
#include "point.hpp"
#include "rayon.hpp"
#include "sphere.hpp"
#include "ecran.hpp"
#include "source.hpp"
#include "scene.hpp"
#include <fstream>
#include <iostream>
#include "controleur.hpp"
#include <fstream> 			 //std::ifstream
#include <string>
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
	string line;

	passerCommentaires(stream);


	//creation camera

	
	stream.getline(line, 5, ' ');
	scene.getCam().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getCam().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	scene.getCam().setZ(atoi(line));
	

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	stream.getline(line, 5, ' ');
	ecran.getTopLeft().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getTopLeft().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	ecran.getTopLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	ecran.getTopRight().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getTopRight().setY(atoi(line));
	stream.getline(line, 5, '\n');
	ecran.getTopRight().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	ecran.getBottomLeft().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getBottomLeft().setY(atoi(line));
	stream.getline(line, 5, '\n');
	ecran.getBottomLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, '\n');
	ecran.setResolution(atoi(line));
	scene.setEcran(ecran);

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getBackground.setR(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getBackground.setG(atoi(line));
	stream.getline(line, 5, '\n');
	scene.getBackground.setB(atoi(line));

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
}

void Controleur::passerCommentaires(ifstream stream)
{
	while(stream.peek() == '#') stream.ignore(256,'\n');

}

void Controleur::passerBlancs(ifstream stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}
