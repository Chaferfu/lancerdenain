#ifndef RAYON_H_INCLUDED
#define RAYON_H_INCLUDED

class Rayon{
private:
	Point origine;
	Point direction;

public:
	Rayon();
	Rayon(const Point origine, const Point dir);
	Point getOrigine() const {return origine;}
	Point getDirection() const {return direction;}

};

#endif