#pragma once
#include "PorteAvion.h"
#include "Croiseur.h"
#include "SousMarin.h"
#include "Torpilleur.h"

class jeu
{
private:
	int maps[2][10][10];
	Navire* navires[2][5];
	void afficherMapJoueur(int index);
	void afficherMapEnnemi(int index);

public:
	jeu();
	~jeu();
	void afficherMaps(int index);
};

