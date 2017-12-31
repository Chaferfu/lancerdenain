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

void Ecran::deleteE(){
	for(unsigned int i = 0; i < resolutionVerticale; ++i) delete[] pixels[i];
	delete[] pixels;
}

Point Ecran::getPixel(const unsigned int i)
{
	
	if(i>resolution*resolutionVerticale-1)
	{
		cout << "ce pixel n'existe pas" << endl;
	}
	//TODO
	float ligne = i/resolution;
	float colonne = i%resolution;

	Point vectUnitaireHorizontal = (topRight - topLeft)/resolution;
	Point vectUnitaireVertical = (bottomLeft - topLeft)/resolutionVerticale;

	Point p(topLeft + vectUnitaireVertical*ligne + vectUnitaireHorizontal*colonne); //on pourrait ajouter la moitie de la taille d'un pixel pour passer pile au centre mais au final c'est pas tres important

	return p;
}