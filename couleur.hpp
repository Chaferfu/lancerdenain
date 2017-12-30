#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

class Couleur{
private:
	int r, g, b;

public:
	Couleur();
	Couleur(const unsigned char r, const unsigned char g, const unsigned char b);
	int getR() const {return r;}
	int getG() const {return g;}
	int getB() const {return b;}
	void setR(const int r) {this->r = r;}
	void setG(const int g) {this->g = g;}
	void setB(const int b) {this->b = b;}
	void calculerCouleur(const int e, const float angle, Couleur ci, Couleur cs);
	void calculerCouleurReflexion(const Couleur cr, const float reflx);
	void afficher(std::ostream &flux) const;
	bool estEgal(Couleur c);
};

#endif