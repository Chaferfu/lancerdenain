#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED
#include <vector>

class Ecran{
private:
	int resolution;
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	std::vector<std::vector<int>> pixels;

public:
	Ecran();
	Ecran(const int res, const Point tl, const Point tr, const Point bl);
	int getReso() const {return resolution;}
	Point getTopLeft() const {return topLeft;}
	Point getTopRight() const {return topRight;}
	Point getBottomLeft() const {return bottomLeft;}
	std::vector<std::vector<int>> getPixels() const {return pixels;}
	void setTopLeft(const Point p) {topLeft = p;}
	void setTopRight(const Point p) {topRight = p;}
	void setBottomLeft(const Point p) {bottomLeft = p;}
	void setResolution(const int r) {resolution = r;}
	void afficher(std::ostream &flux) const;	
	
};

#endif