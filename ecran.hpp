#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED

class Ecran{
private:
	float resolution;
	Point topLeft;
	Point topright;
	Point bottomLeft;


public:
	Ecran();
	Ecran(const float reso, const Point pos);
	float getReso() const {return resolution;}
	Point getPos() const {return position;}
};

#endif