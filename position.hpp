#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
private:
	float x, y, z;

public:
	Point();
	Point(float x, float y, float z);
	float getX() const {return x;}
	float getY() const {return y;}
	float getZ() const {return z;}
	void setX(float x) {this->x = x;}
	void setY(float y) {this->y = y;}
	void setZ(float z) {this->z = z;}
};

#endif