#include <iostream>
#include <ostream>
#include "couleur.hpp"
#include <math.h>
using namespace std;

Couleur::Couleur(){
	
}

Couleur::Couleur(const unsigned char r, const unsigned char g, const unsigned char b){
	this->r = r;
	this->g = g;
	this->b = b;

}

void Couleur::calculerCouleur(const int e, const float angle, Couleur ci, Couleur cs){
	//if(e == 1)
		//cout << e << " " << angle << " couleurs :" << (int)ci.getR() << " " << (int)cs.getR() << endl;
	r = e*cos(angle)*((int)ci.getR()*(int)cs.getR())/255; //if(e==1) cout << "angle : " << angle << " r : " << r << " autre r : " << (int)ci.getR() << endl;
	g = e*cos(angle)*((int)ci.getG()*(int)cs.getG())/255;
	b = e*cos(angle)*((int)ci.getB()*(int)cs.getB())/255;
}

void Couleur::afficher(std::ostream &flux) const{
	flux <<  r << " " << g << " " << b << endl;
}

bool Couleur::estEgal(Couleur c){
	return r == c.r && g == c.g && b == c.b;
}

