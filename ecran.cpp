#include <iostream>
#include "ecran.hpp"

void Duree::afficher(ostream &flux) const
{
    flux << "Ecran:" << endl << "posTL :"<< topLeft << "  posTR :" << topRight << "posBL" << bottomLeft << "resoultion : " << resolution << endl << endl;
}