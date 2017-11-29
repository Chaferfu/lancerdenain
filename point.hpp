#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
private:
	float x, y, z;

public:
	Point();
	Point(float x, float y, float z);
	float getX() {return x;}
	float getY() {return y;}
	float getZ() {return z;}
};

#endif;