#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED

class Ecran{
private:
	int resolution;
	Point topLeft;
	Point topRight;
	Point bottomLeft;


public:
	Ecran();
	Ecran(const float reso, const Point pos);
	int getReso() const {return resolution;}
	Point getTopLeft() const {return topLeft;}
	Point getTopRight() const {return topRight;}
	Point getBottomLeft() const {return bottomLeft;}
	void setTopLeft(Point p) {topLeft = p;}
	void setTopRight(Point p) {topRight = p;}
	void setBottomLeft(Point p) {bottomLeft = p;}
};

#endif