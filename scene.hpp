#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <vector>
#include <iostream>
#include <algorithm>
#include "sphere.hpp"
#include "ecran.hpp"
#include "source.hpp"
#include "rayon.hpp"

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
	Scene(const Point c, const Ecran& e, const Source s, Couleur bg, std::vector<Sphere> v);
	Point getCam() const {return camera;}
	Ecran getEcran() const {return ecran;}
	Source getSource() const {return source;}
	std::vector<Sphere> getSpheres() const {return spheres;}
	void setCam(const Point cam) {camera = cam;}
	void setEcran(const Ecran& ecran) {this->ecran = ecran;}
	void addSphere(const Sphere s);
	void ecrirePPM();
	Point getIntersection(Rayon r);
};

Scene parse();
void passerCommentaires(std::ifstream &stream);
void passerBlancs(std::ifstream &stream);
std::ostream& operator<<( std::ostream &flux,const Ecran & e );
std::ostream& operator<<( std::ostream &flux,const Point & p );
std::ostream& operator<<( std::ostream &flux,const Source & s );
std::ostream& operator<<( std::ostream &flux,const Couleur & c );
std::ostream& operator<<( std::ostream &flux,const Sphere & c );




#endif 