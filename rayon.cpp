#include "rayon.hpp"

Rayon::Rayon(const Point origine, const Point dir){
	this->origine = origine;
	this->direction = dir - origine;
}

Rayon::Rayon()
{

}
