#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <iostream>

class Point{
protected:
	float x, y, z;

public:
	Point();
	Point(const float x, const float y, const float z);
	float getX() const {return x;}
	float getY() const {return y;}
	float getZ() const {return z;}
	void setX(const float x) {this->x = x; }
	void setY(const float y) {this->y = y;}
	void setZ(const float z) {this->z = z;}
	void afficher(std::ostream &flux) const;	
	float distance(const Point other) const;


	Point& operator+=(const Point& rhs) 
	{                           
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Point operator+(Point lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const Point& rhs) // otherwise, both parameters may be const references
	{
	  lhs += rhs; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)
	}

	Point& operator-=(const Point& rhs) 
	{                           
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Point operator-(Point lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const Point& rhs) // otherwise, both parameters may be const references
	{
	  lhs -= rhs; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)
	}

	Point& operator*=(const float f) 
	{                           
		x *= f;
		y *= f;
		z *= f;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Point operator*(Point lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const float f) // otherwise, both parameters may be const references
	{
	  lhs *= f; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)

	}


	Point& operator/=(const float f) 
	{                           
		x /= f;
		y /= f;
		z /= f;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Point operator/(Point lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const float f) // otherwise, both parameters may be const references
	{
	  lhs /= f; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)

	}

};

#endif