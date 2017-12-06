#include "sphere.hpp"

Sphere::Sphere(const float r, const Point c, const Couleur coul, const float reflex){
	rayon = r;
	centre = c;
	couleur = coul;
	reflexivite = reflex;
}