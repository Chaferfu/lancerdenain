#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

class Controleur
{
private:
	Scene scene;

public:
	Controleur(const Scene s);
	Scene getScene() const {return scene;}
	void parse(const char* path);
	
};

#endif