#include "sphere.hpp"

Sphere::Sphere(const float r, const Point c, const Couleur coul, const float reflex){
	rayon = r;
	centre = c;
	couleur = coul;
	reflexivite = reflex;
}

Sphere::Sphere(const float centerX, const float centerY,const float centerZ,const float r,const int colorR,const int colorG,const int colorB,const float reflx)
{
	rayon = r;
	centre.setX(centerX);
	centre.setY(centerY);
	centre.setZ(centerZ);
	couleur.setR(colorR);
	couleur.setG(colorG);
	couleur.setB(colorB);
	reflexivite = reflx;
}