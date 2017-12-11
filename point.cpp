#include <iostream>
#include "point.hpp"
#include "controleur.hpp"

Point::Point(){
	
}

Point::Point(const float x, const float y, const float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::afficher(std::ostream &flux) const
{
    flux << "Point:" << "\n" << "x :"<< x << "  y:" << y << "z:" << z << "\n\n" << std::endl;
}
