#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

class Controleur
{
private:
	Scene scene;

public:
	Controleur(const Scene s);
	Controleur();
	Scene getScene() const {return scene;}
	void parse();
	void passerCommentaires(std::ifstream &stream);
	void passerBlancs(std::ifstream &stream);
};

#endif