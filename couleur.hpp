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
	void calculerCouleurReflexion(const int e, const float angle, const Couleur cr, const Couleur cs, const float reflx);
	void ajouterReflexion(const Couleur cr, const float reflx);
	void reflexiondansleneant(Couleur c, float reflx);
	void afficher(std::ostream &flux) const;
	bool estEgal(Couleur c);

	Couleur& operator+=(const Couleur& rhs) 
	{                           
		r += rhs.r;
		g += rhs.g;
		b += rhs.b;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Couleur operator+(Couleur lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const Couleur& rhs) // otherwise, both parameters may be const references
	{
	  lhs += rhs; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)
	}

	Couleur& operator-=(const Couleur& rhs) 
	{                           
		r -= rhs.r;
		g -= rhs.g;
		b -= rhs.b;	
		return *this;
	}
	 
	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend Couleur operator-(Couleur lhs,        // passing lhs by value helps optimize chained a+b+c
	                   const Couleur& rhs) // otherwise, both parameters may be const references
	{
	  lhs -= rhs; // reuse compound assignment
	  return lhs; // return the result by value (uses move constructor)
	}

	Couleur& operator*=(const float f) 
	{                           
		r *= f;
		g *= f;
		b *= f;	
		return *this;
	}
	 
	
	friend Couleur operator*(Couleur lhs, const float f)
	{
	  lhs *= f; 
	  return lhs;
	}

	friend Couleur operator*(const float f, Couleur lhs)
	{
	  lhs *= f; 
	  return lhs;
	}
};

#endif