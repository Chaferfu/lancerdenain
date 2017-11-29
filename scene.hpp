#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <vector>

class Scene 
{
private:
	vector<Sphere> spheres;
	Point camera;
	Ecran ecran;
	Source source;

public:
	Scene(const Point c,const Ecran e, const Source s);
	addSphere(const Sphere s);

#endif 