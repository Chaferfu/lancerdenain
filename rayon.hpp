#ifndef RAYON_H_INCLUDED
#define RAYON_H_INCLUDED
#include <math.h>
#include "point.hpp"

class Rayon{
private:
	Point origine;
	Point direction;
	Point courant; // Le point en tête du rayon à l'instant t

public:
	Rayon();
	Rayon(const Point origine, const Point dir);
	Point getOrigine() const {return origine;}
	Point getDirection() const {return direction;}
};

#endif