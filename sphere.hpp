#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED
#include "point.hpp"
#include "couleur.hpp"

class Sphere{
private:
	float rayon, reflexivite;
	Point centre;
	Couleur couleur;

public:
	Sphere();
	Sphere(const float r, const Point c, const Couleur coul, const float reflex);
	Sphere(const float centerX, const float centerY,const float centerZ,const float r,const int colorR,const int colorG,const int colorB,const float reflx);
	float getRayon() const {return rayon;}
	float getReflex() const {return reflexivite;}
	Point getCentre() const {return centre;}
	Couleur getCouleur() const {return couleur;}
};

#endif