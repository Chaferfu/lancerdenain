#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
private:
	float x, y, z;

public:
	Point();
	Point(const float x, const float y, const float z);
	float getX() const {return x;}
	float getY() const {return y;}
	float getZ() const {return z;}
	void setX(const float x) {this->x = x;}
	void setY(const float y) {this->y = y;}
	void setZ(const float z) {this->z = z;}
};

#endif