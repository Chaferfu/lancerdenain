#include "couleur.hpp"
#include <math.h>
using namespace std;

Couleur::Couleur(){
	
}

void Couleur::calculerCouleur(const int e, const float angle, const Couleur ci, const Couleur cs){
	r = e*cos(angle)*ci.getR()*cs.getR()/255;
	g = e*cos(angle)*ci.getG()*cs.getG()/255;
	b = e*cos(angle)*ci.getB()*cs.getB()/255;
}