#include "controleur.hpp"
#include <fstream> 	
#include <stdlib>		 //std::ifstream
#include <string>
#include <sstream>
using namespace std;


Controleur::Controller(const Scene s)
{
	scene = s;
}

int main(int argc, char const *argv[])
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
	scene.getCamera().setX(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getCamera().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	scene.getCamera().setZ(atoi(line));
	

	passerBlancs(stream);
	passerCommentaires(stream);

	//creation screen pos top left

	Ecran ecran;

	stream.getline(line, 5, ' ');
	ecran.getTopLeft().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getTopLeft().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	ecran.getTopLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	ecran.getTopright().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getTopright().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	ecran.getTopright().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	ecran.getBottomLeft().setX(atoi(line));
	stream.getline(line, 5, ' ');
	ecran.getBottomLeft().setY(atoi(line));
	sstream.getline(line, 5, '\n');
	ecran.getBottomLeft().setZ(atoi(line));

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	ecran.setResolution(atoi(line));
	scene.setEcran(ecran);

	passerBlancs(stream);
	passerCommentaires(stream);

	stream.getline(line, 5, ' ');
	scene.getBackground.setR(atoi(line));
	stream.getline(line, 5, ' ');
	scene.getBackground.setG(atoi(line));
	stream.getline(line, 5, ' ');
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
	stream.getline(line, 5, ' ');
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

		}

	}
}

void Controleur::passerCommentaires(ifstream stream)
{
	while(stream.peek() == '#') stream.ignore(numeric_limits<streamsize>::max(),'\n');

}

void Controleur::passerBlancs(ifstream stream)
{
	while(stream.peek() == '\n' || stream.peek() == ' ') stream.ignore(1);
}
