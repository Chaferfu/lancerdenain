#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

class Sphere{
private:
	float rayon, reflexivite;
	Point centre;
	Couleur couleur;

public:
	Sphere();
	Sphere(const float r, const Point c, const Couleur coul, const float reflex);
	float getRayon() const {return rayon;}
	float getReflex() const {return reflexivite;}
	Point getCentre() const {return centre;}
	Couleur getCouleur() const {return couleur;}
};

#endif