#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <ostream>
#include "couleur.hpp"

class Objet{
protected:
	Couleur couleur;
	float reflexivite;

public:
	Objet();
	Objet(Couleur c, float ref) : couleur(c), reflexivite(ref) {}
	float getReflex() const {return reflexivite;}
	Couleur getCouleur() const {return couleur;}
};

#endif