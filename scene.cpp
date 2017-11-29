#include <vector>

Scene::Scene(Point c, Ecran e, Source s)
{
	camera = c;
	ecran = e;
	source = s;
}

Scene::addSphere(const Sphere s)
{
	spheres.push_back(s);
}