#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

class Controleur
{
private:
	Scene scene;

public:
	Controleur(const Scene s);
	Scene getScene() const {return scene;}
	void parse();
	void passerCommentaires(std::ifstream const &stream);
	void passerBlancs(std::ifstream const &stream);
};

#endif