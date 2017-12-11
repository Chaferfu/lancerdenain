#include <iostream>
#include "point.hpp"

Point::Point(const float x, const float y, const float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::afficher(ostream &flux) const
{
    flux << "Point:" << endl << "x :"<< x << "  y:" << y << "z:" << z << endl << endl;
}