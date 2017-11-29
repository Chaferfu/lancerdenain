#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED

class Sphere{
private:
	float rayon, reflexivite;
	Point centre;

public:
	Sphere();
	float getRayon() {return rayon;}
	float getReflex() {return reflexivite;}
	Point getCentre() {return centre;}
};

#endif