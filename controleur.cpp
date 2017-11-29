#include "controleur.hpp"
#include <fstream> 	
#include <stdlib>		 //std::ifstream
using namespace std;


Controleur::Controller(const Scene s)
{
	scene = s;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}

void Controleur::parse(const char* path)
{


	ifstream stream("In.txt", ifstream::in);

	passerCommentaires(stream);
	char *buffer;


	//creation camera

	Point camera;
	stream.getLine(buffer, 5, ' ');
	camera.getPosition().setX(atoi(buffer));
	stream.getLine(buffer, 5, ' ');
	camera.getPosition().setY(atoi(buffer));
	sstream.getLine(buffer, 5, '\n');
	camera.getPosition().setZ(atoi(buffer));
	scene.camera = camera;

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	Ecran  ecran;

	stream.getLine(buffer, 5, ' ');
	ecran.getTopLeft().setX(atoi(buffer));
	stream.getLine(buffer, 5, ' ');
	ecran.getTopLeft().setY(atoi(buffer));
	sstream.getLine(buffer, 5, '\n');
	ecran.getTopLeft().setZ(atoi(buffer));
	

	stream.getLine(buffer, 5, ' ');
	ecran.getTopLeft().setX(atoi(buffer));
	stream.getLine(buffer, 5, ' ');
	ecran.getTopright().setY(atoi(buffer));
	sstream.getLine(buffer, 5, '\n');
	ecran.getTopright().setZ(atoi(buffer));
	scene.ecran = ecran;

	stream.getLine(buffer, 5, ' ');
	ecran.getBottomLeft().setX(atoi(buffer));
	stream.getLine(buffer, 5, ' ');
	ecran.getBottomLeft().setY(atoi(buffer));
	sstream.getLine(buffer, 5, '\n');
	ecran.getBottomLeft().setZ(atoi(buffer));
	scene.ecran = ecran;


}

void Controleur::passerCommentaires(ifstream stream)
{
	while(stream.peek() == '#') stream.ignore(numeric_limits<streamsize>::max(),'\n');

}

void Controleur::passerBlancs(ifstream stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}
