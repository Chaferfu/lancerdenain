#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include "sphere.hpp"
#include "ecran.hpp"
#include "rayon.hpp"
#include "pointcolore.hpp"

class Scene {
private:
	std::vector<Sphere> spheres;
	int idCourant; // Position dans le vecteur de la sphère sur laquelle on travaille
	Point camera;
	Ecran ecran;
	PointColore source;
	Couleur background;

public:
	Couleur getBackground() const {return background;};
	Scene();
	Scene(const Point c, const Ecran& e, const PointColore s, Couleur bg, std::vector<Sphere> v);
	Point getCam() const {return camera;}
	Ecran getEcran() const {return ecran;}
	PointColore getSource() const {return source;}
	std::vector<Sphere> getSpheres() const {return spheres;}
	int getId() const {return idCourant;}
	void setCam(const Point cam) {camera = cam;}
	void setEcran(const Ecran& ecran) {this->ecran = ecran;}
	void addSphere(const Sphere s);
	float calculerAngle(PointColore p);
	void ecrirePPM();
	bool estVisible(PointColore p);
	PointColore getIntersection(Rayon r);
	void rayTracing();
	Rayon rayonReflechi(const Rayon incident);
	void reflexion(PointColore pcref, int i, int j, float reflx);
	Couleur couleurDuPoint(PointColore pc);


};

Scene parse(char* input);
void passerCommentaires(std::ifstream &stream);
void passerBlancs(std::ifstream &stream);
std::ostream& operator<<( std::ostream &flux,const Ecran & e );
std::ostream& operator<<( std::ostream &flux,const Point & p );
std::ostream& operator<<( std::ostream &flux,const PointColore & s );
std::ostream& operator<<( std::ostream &flux,const Couleur & c );
std::ostream& operator<<( std::ostream &flux,const Sphere & c );




#endif 