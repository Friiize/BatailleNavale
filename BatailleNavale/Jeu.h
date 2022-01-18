#pragma once
#include "PorteAvion.h"
#include "Croiseur.h"
#include "SousMarin.h"
#include "Torpilleur.h"

class Jeu
{
private:
	int maps[2][MAP_SIZE][MAP_SIZE];
	Navire* navires[2][5];
	void afficherMapJoueur(int index);
	void afficherMapEnnemi(int index);
	Pos SetNavPos();
public:
	Jeu();
	~Jeu();
	void Start();
	void init();
	void GameLoop();
	void ShootTurn(int index);
	int** GetMaps(int index);
	Navire* GetNavire(int index, int indexNavire);
	Navire* GetNavires();
	void afficherMaps(int index);
	bool shipHasPlace(int index, int indexNavire);
};

