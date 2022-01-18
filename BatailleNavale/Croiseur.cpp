#include "Jeu.h"

Croiseur::Croiseur(bool isHoriz, int x, int y) : Navire(NavireType::Croiseur, isHoriz, x, y)
{
}

void Croiseur::Init() {
	bool isPlaced = false;
	bool horiz = false;
	Pos temp;
	int input = -1;

	while (!isPlaced) {
		while (input < 0 || input > 1) {
			system("cls");
			cout << "\nConfiguration du croiseur : \nHorizontale ou verticale ? 0 ou 1\n";
			cin >> input;
		}
		horiz = (input == 0) ? true : false;
		temp = this->SetNavPos();
		this->x = temp.x;
		this->y = temp.y;
		this->isHoriz = horiz;
		isPlaced = this->shipHasPlace(i, 4);
	}
}

void Croiseur::GetTorpPos(Torpilleur* cible, Jeu* running, int index)
{
	int random = rand() % 2;
	if (cible->GetPos()[random].etat == EtatCase::Cache)
	{
		cible->GetPos()[random].etat = EtatCase::Visible;
		running->GetMaps(index)[cible->GetPos()[random].y][cible->GetPos()[random].x] = 4;
	}
	else if (cible->GetPos()[random].etat == EtatCase::ToucheCache)
	{
		cible->GetPos()[random].etat = EtatCase::Touche;
		running->GetMaps(index)[cible->GetPos()[random].y][cible->GetPos()[random].x] = 3;
	}
}
