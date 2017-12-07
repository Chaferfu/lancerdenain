#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include <vector>
#include "sphere.hpp"
#include "ecran.hpp"
#include "source.hpp"

class Scene {
private:
	std::vector<Sphere> spheres;
	Point camera;
	Ecran ecran;
	Source source;
	Couleur background;

public:

	Couleur getBackground() const {return background;};
	Scene();
	Scene(const Point c, const Ecran e, const Source s);
	Point getCam() const {return camera;}
	Ecran getEcran() const {return ecran;}
	Source getSource() const {return source;}
	std::vector<Sphere> getSpheres() const {return spheres;}
	void setCam(const Point cam) {camera = cam;}
	void setEcran(const Ecran ecran) {this->ecran = ecran;}
	void addSphere(const Sphere s);
};

#endif 