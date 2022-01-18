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
	int countdown[2];
	void afficherMapJoueur(int index);
	void afficherMapEnnemi(int index);

public:
	Jeu();
	~Jeu();
	void Start();
	//void init();
	int GameLoop();
	void ShootTurn(int index);
	int GetMapCase(int index, int y, int x);
	void SetMapValue(int index, int y, int x, int value);
	Pos SetNavPos();
	Navire* GetNavire(int index, int indexNavire);
	//Navire*** GetNavires();
	int GetCountdown(int index);
	void SetCountdown(int index, int x);
	void afficherMaps(int index);
	bool shipHasPlace(int index, Navire* navire);
};

