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
	Couleur background;

public:
	Scene(const Point c,const Ecran e, const Source s);
	void addSphere(const Sphere s);
	void getBackground() const {return background;};

#endif 