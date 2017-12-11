#include <vector>
#include "point.hpp"
#include "rayon.hpp"
#include "couleur.hpp"
#include "source.hpp"
#include "scene.hpp"

Scene::Scene(){
	
}

Scene::Scene(Point c, Ecran e, Source s)
{
	camera = c;
	ecran = e;
	source = s;
}

void Scene::addSphere(const Sphere s)
{
	spheres.push_back(s);
}

Rayon Scene::genererRayon(Point p){
	return Rayon(camera, p);
}