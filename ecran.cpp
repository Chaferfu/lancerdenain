#include <iostream>
#include <ostream>
#include "point.hpp"
#include "scene.hpp"
#include "ecran.hpp"




void Ecran::afficher(std::ostream &flux) const
{
    flux << "Ecran: \n" << "posTL :"<< topLeft << "  posTR :" << 
    topRight << "posBL" << bottomLeft << "resolution : " << resolution << "\n\n" << std::endl;
}


Ecran::Ecran(){
	
}

Ecran::Ecran(const int res, const Point tl, const Point tr, const Point bl){
	resolution = res;
	topLeft = tl;
	topRight = tr;
	bottomLeft = bl;
}