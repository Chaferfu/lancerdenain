#include <iostream>
#include "math.h"
#include "point.hpp"


Point::Point(){
	//x= 40;
}

Point::Point(const float x, const float y, const float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::afficher(std::ostream &flux) const
{
    flux << "Point:  " << "x :"<< x << "  y:" << y << "  z:" << z << "\n\n" << std::endl;
}

float Point::distance(const Point other) const
{
	float xx, yy, zz;
	xx = x - other.x;
	yy = y - other.y;
	zz = z - other.z;

	return sqrt(xx*xx + yy*yy + zz*zz);
}

float Point::norme(){
	return sqrt(x*x + y*y + z*z);
}

float Point::scalaire(const Point other){
	return x*other.x + y*other.y + z*other.z;
}