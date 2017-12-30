#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <ostream>
#include "couleur.hpp"

class Objet{
protected:
	float reflexivite;
	Couleur couleur;

public:
	Objet();
	Objet(Couleur c) : couleur(c) {}
	float getReflex() const {return reflexivite;}
	Couleur getCouleur() const {return couleur;}
};

#endif