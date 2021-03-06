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

	//calcul de la couleur avec la formule du sujet
	r = e*cos(angle)*(ci.getR()*cs.getR())/255;
	g = e*cos(angle)*(ci.getG()*cs.getG())/255;
	b = e*cos(angle)*(ci.getB()*cs.getB())/255;
}

void Couleur::calculerCouleurReflexion(const int e, const float angle,const Couleur cr,const Couleur cs, const float reflx)
{
	r = (1 - reflx)*r + reflx*e*cos(angle)*(cr.getR()*cs.getR())/255;
	g = (1 - reflx)*g + reflx*e*cos(angle)*(cr.getG()*cs.getG())/255;
	b = (1 - reflx)*b + reflx*e*cos(angle)*(cr.getB()*cs.getB())/255;
}

void Couleur::ajouterReflexion(const Couleur cr, const float reflx)
{
	r = (1 - reflx)*r + reflx*cr.getR();
	g = (1 - reflx)*g + reflx*cr.getG();
	b = (1 - reflx)*b + reflx*cr.getB();
}

void Couleur::ajouterAmbiance(Couleur c)
{
	Couleur nouvelle = *this + c; 

	//255 est la valeur maximale pour une couleur rgb dans un .ppm
	if (nouvelle.r > 255) r = 255;
	else r = nouvelle.r;

	if (nouvelle.g > 255) g = 255;
	else g = nouvelle.g;

	if (nouvelle.b > 255) b = 255;
	else b = nouvelle.b;
}

void Couleur::reflexiondansleneant(Couleur c, float reflx)
{
	r = (1 - reflx)*r + reflx*c.getR();
	g = (1 - reflx)*g + reflx*c.getG();
	b = (1 - reflx)*b + reflx*c.getB();
}

void Couleur::afficher(std::ostream &flux) const{
	flux <<  r << " " << g << " " << b << endl;
}

bool Couleur::estEgal(Couleur c){
	return r == c.r && g == c.g && b == c.b;
}

