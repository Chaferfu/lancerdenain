#include "point.hpp"
#include "couleur.hpp"
#include "source.hpp"

Source::Source(){
	
}

Source::Source(Point p, Couleur c){
	pos = p;
	couleur = c;
}
