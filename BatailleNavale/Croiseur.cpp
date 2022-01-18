#include "Jeu.h"

Croiseur::Croiseur(bool isHoriz, int x, int y) : Navire(NavireType::Croiseur, isHoriz, x, y)
{
}

void Croiseur::GetTorpPos(Torpilleur* cible, Jeu* running, int index)
{
	int random = rand() % 2;
	cible->GetPos()[random].etat = EtatCase::Visible;
	running->GetMaps(index)[cible->GetPos()[random].y][cible->GetPos()[random].x] = 4;
}
