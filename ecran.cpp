#include <iostream>
#include <ostream>
#include "point.hpp"
#include "scene.hpp"
#include "ecran.hpp"
using namespace std;


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

	int resoVert = res;
	vector<vector<Couleur>>::iterator it;

	/*pixels.resize(res);
	for(unsigned int i = 0; i < pixels.size(); i++)
		pixels.get(i).resize(res);*/
	//for(it = pixels.begin(), it != pixels.end(); ++it)

}