#include <iostream>
#include <ostream>
#include "point.hpp"
#include "scene.hpp"
#include "ecran.hpp"
using namespace std;


void Ecran::afficher(std::ostream &flux) const
{
    flux << "Ecran: \n" << "posTL :"<< topLeft << "  posTR :" << 
    topRight << "posBL" << bottomLeft << "resolution : " << resolution << "\n\n" << std::endl;
}

Ecran::Ecran(){
	
}

Ecran::Ecran(const int res, const Point tl, const Point tr, const Point bl){
	resolution = res;
	topLeft = tl;
	topRight = tr;
	bottomLeft = bl;

	// Calcul de la résolution verticale :
	resolutionVerticale = (topLeft.getY() - bottomLeft.getY())*(res/(topRight.getX() - topLeft.getX()));

	pixels = new Couleur*[resolutionVerticale];
	for(unsigned int i = 0; i < resolutionVerticale; ++i) pixels[i] = new Couleur[resolution];

}

// Je pensais qu'on aurait besoin à cause du resize() de "pixels", mais 
// valgrind dit que tout va bien
Ecran::~Ecran(){

	for(unsigned int i = 0; i < resolutionVerticale; ++i) delete pixels[i]; 
	delete pixels;

	
}