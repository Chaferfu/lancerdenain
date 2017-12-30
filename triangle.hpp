#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include "objet.hpp"

class Triangle: public Objet{
private:
	Point p1;
	Point p2;
	Point p3;

public:
	Triangle(const Point pp1, const Point pp2, const Point pp3) : Objet(Couleur(21, 121,21)), p1(pp1), p2(pp2), p3(pp3) {}
	Point getP1() const {return p1;}
	Point getP2() const {return p2;}
	Point getP3() const {return p3;}
};

#endif