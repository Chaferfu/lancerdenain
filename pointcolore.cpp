#include "pointcolore.hpp"

/*PointColore::PointColore(const float xx, const float yy, const float zz, const Couleur c){
	//Point(x, y, z);
	x = xx;
	y = yy;
	z = zz;
	coul = c;
}*/

PointColore::PointColore(){
	
}

bool PointColore::estEgal(PointColore p){
	return x == p.x && y == p.y && z == p.z && coul.estEgal(p.coul); 
}

/*
bool operator==(Couleur const& a, Couleur const& b){
    return a.estEgal(b);
}*/