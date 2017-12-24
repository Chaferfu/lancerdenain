#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

class Couleur{
private:
	int r, g, b;

public:
	Couleur();
	Couleur(const unsigned char r, const unsigned char g, const unsigned char b);
	unsigned char getR() const {return r;}
	unsigned char getG() const {return g;}
	unsigned char getB() const {return b;}
	void setR(const unsigned char r) {this->r = r;}
	void setG(const unsigned char g) {this->g = g;}
	void setB(const unsigned char b) {this->b = b;}
	void calculerCouleur(const int e, const float angle, Couleur ci, Couleur cs);
	void afficher(std::ostream &flux) const;
	bool estEgal(Couleur c);
};

#endif