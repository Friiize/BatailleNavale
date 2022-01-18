#include "Jeu.h"

Croiseur::Croiseur(bool isHoriz, int x, int y) : Navire(NavireType::Croiseur, isHoriz, x, y)
{
}

void Croiseur::UseAbility(Jeu* running, int index)
{
	Navire* cible = NULL;
	for (int i = 0; i < 5; i++)
		if (running->GetNavire(index, i)->GetNavireType() == NavireType::Torpilleur)
			cible = running->GetNavire(index, i);
	int random = rand() % 2;
	if (cible->GetPos()[random].etat == EtatCase::Cache)
	{
		cible->GetPos()[random].etat = EtatCase::Visible;
		running->GetMap(index)[cible->GetPos()[random].y][cible->GetPos()[random].x] = 4;
	}
	else if (cible->GetPos()[random].etat == EtatCase::ToucheCache)
	{
		cible->GetPos()[random].etat = EtatCase::Touche;
		running->GetMap(index)[cible->GetPos()[random].y][cible->GetPos()[random].x] = 3;
	}
}
