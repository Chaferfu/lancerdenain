#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

class Source{
private:
	Point pos;
	Couleur couleur;

public:
	Source();
	Source(Point p, Couleur c);
	Point getPos() const {return pos;}
	Couleur getCouleur() const {return couleur;}
	void afficher(std::ostream &flux) const;
};

#endif
