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

