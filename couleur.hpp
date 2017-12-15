#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

class Couleur{
private:
	int r, g, b;

public:
	Couleur();
	Couleur(const int r, const int g, const int b);
	int getR() const {return r;}
	int getG() const {return g;}
	int getB() const {return b;}
	void setR(const int r) {this->r = r;}
	void setG(const int g) {this->g = g;}
	void setB(const int b) {this->b = b;}
	void calculerCouleur(const int e, const float angle, const Couleur ci, const Couleur cs);
	void afficher(std::ostream &flux) const;
};

#endif