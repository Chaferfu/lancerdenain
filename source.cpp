#include <iostream>
#include <ostream>
#include "point.hpp"
#include "couleur.hpp"
#include "scene.hpp"
#include "source.hpp"

Source::Source(){
	
}

Source::Source(Point p, Couleur c){
	pos = p;
	couleur = c;
}

void Source::afficher(std::ostream &flux) const
{
	flux << "pos :" << pos << "couleur :" << couleur << std::endl;
}