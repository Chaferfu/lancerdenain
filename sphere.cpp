#include <iostream>
#include <ostream>
#include "scene.hpp"
#include "rayon.hpp"
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

void Sphere::afficher(std::ostream &flux) const
{
	flux << "SPHERE ::\tposition:" << centre << " rayon:" << rayon << " couleur:" << couleur << " reflexivite" << reflexivite << std::endl;
}

Rayon Sphere::normale(const Point intersection)
{
	Point vNormale = intersection - centre;
	vNormale = vNormale/vNormale.norme();
	Rayon reflechi(intersection, vNormale);
	return reflechi;
}
