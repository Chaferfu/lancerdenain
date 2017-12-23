#ifndef POINT_COLORE_INCLUDED
#define POINT_COLORE_INCLUDED
#include "point.hpp"
#include "couleur.hpp"

class PointColore: public Point{
private:
	Couleur coul;

public:
	PointColore(const float x, const float y, const float z, const Couleur c) : Point(x, y, z), coul(c){}
	Couleur getCouleur() const {return coul;}
};

#endif