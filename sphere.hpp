#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED
#include "point.hpp"
#include "couleur.hpp"
#include "rayon.hpp"
#include "objet.hpp"

class Sphere: public Objet{
private:
	float rayon;
	Point centre;

public:
	Sphere(const float r, const Point c, const Couleur coul, const float reflex);
	Sphere(const float centerX, const float centerY,const float centerZ,const float r,const int colorR,const int colorG,const int colorB,const float reflx);
	float getRayon() const {return rayon;}
	Point getCentre() const {return centre;}
	bool contient(const Point p) const;
	void afficher(std::ostream &flux) const;
	Point normale(const Point intersection);

};

#endif