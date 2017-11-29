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
};

#endif;