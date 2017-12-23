#include <iostream>
#include <ostream>
#include "couleur.hpp"
#include <math.h>
using namespace std;

Couleur::Couleur(){
	
}

Couleur::Couleur(const int r, const int g, const int b){
	this->r = r;
	this->g = g;
	this->b = b;

}

void Couleur::calculerCouleur(const int e, const float angle, const Couleur ci, const Couleur cs){
	r = e*cos(angle)*ci.getR()*cs.getR()/255;
	g = e*cos(angle)*ci.getG()*cs.getG()/255;
	b = e*cos(angle)*ci.getB()*cs.getB()/255;
}

void Couleur::afficher(std::ostream &flux) const
{
	flux <<  r << " " << g << " " << b << endl;
}
