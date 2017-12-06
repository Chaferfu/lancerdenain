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
//#include <stdlib>		 //std::ifstream
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

	passerCommentaires(stream);
	char *buffer;


	//creation camera

	Point camera;
	stream.getline(buffer, 5, ' ');
	scene.getCam().setX(atoi(buffer));
	stream.getline(buffer, 5, ' ');
	scene.getCam().setY(atoi(buffer));
	stream.getline(buffer, 5, '\n');
	scene.getCam().setZ(atoi(buffer));
	scene.setCam(camera);

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	Ecran ecran;

	stream.getline(buffer, 5, ' ');
	ecran.getTopLeft().setX(atoi(buffer));
	stream.getline(buffer, 5, ' ');
	ecran.getTopLeft().setY(atoi(buffer));
	stream.getline(buffer, 5, '\n');
	ecran.getTopLeft().setZ(atoi(buffer));
	

	stream.getline(buffer, 5, ' ');
	ecran.getTopLeft().setX(atoi(buffer));
	stream.getline(buffer, 5, ' ');
	ecran.getTopRight().setY(atoi(buffer));
	stream.getline(buffer, 5, '\n');
	ecran.getTopRight().setZ(atoi(buffer));
	scene.setEcran(ecran);

	stream.getline(buffer, 5, ' ');
	ecran.getBottomLeft().setX(atoi(buffer));
	stream.getline(buffer, 5, ' ');
	ecran.getBottomLeft().setY(atoi(buffer));
	stream.getline(buffer, 5, '\n');
	ecran.getBottomLeft().setZ(atoi(buffer));
	scene.setEcran(ecran);


}

void Controleur::passerCommentaires(ifstream stream)
{
	while(stream.peek() == '#') stream.ignore(numeric_limits<streamsize>::max(),'\n');

}

void Controleur::passerBlancs(ifstream stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}
