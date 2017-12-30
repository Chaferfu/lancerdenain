#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

class Objet{
protected:
	float reflexivite;
	Couleur couleur;

public:
	float getReflex() const {return reflexivite;}
	Couleur getCouleur() const {return couleur;}
};

#endif