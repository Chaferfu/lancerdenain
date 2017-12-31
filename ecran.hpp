#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED
#include <vector>

class Ecran{
private:
	unsigned int resolution; //horizontale
	unsigned int resolutionVerticale;
	Point topLeft;
	Point topRight;
	Point bottomLeft;
	Couleur ** pixels; //tableau dans lequel sont stockées les couleurs visibles

public:
	Ecran();

	Ecran(const int res, const Point tl, const Point tr, const Point bl);

	/* detruit proprement le tableau alloué dynamiquement */
	void deleteE();

	unsigned int getReso() const {return resolution;}
	unsigned int getResolutionVerticale() const {return resolutionVerticale;}
	Point getTopLeft() const {return topLeft;}
	Point getTopRight() const {return topRight;}
	Point getBottomLeft() const {return bottomLeft;}
	Point getPixel(const unsigned int i);
	Couleur ** getPixels() const {return pixels;}
	void setTopLeft(const Point p) {topLeft = p;}
	void setTopRight(const Point p) {topRight = p;}
	void setBottomLeft(const Point p) {bottomLeft = p;}
	void setResolution(const int r) {resolution = r;}

	/* affiche les attributs de l'ecran dans le stream*/
	void afficher(std::ostream &flux) const;	
	
};

#endif