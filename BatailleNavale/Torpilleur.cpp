#include "Jeu.h"

Torpilleur::Torpilleur(bool isHoriz, int x, int y) : Navire(NavireType::Torpilleur, isHoriz, x, y)
{
}

void Torpilleur::Shoot(int y, int index, Jeu* running)
{
	int i = 1;
	bool hit = false;
	while (i < 11 && !hit)
	{
		if (running->GetMaps(index)[y][i] != 0 || running->GetMaps(index)[y][i] != 1)
		{
			hit = true;
			running->GetMaps(index)[y][i] = 3;
			for (int j = 0; j < 5; j++)
			{
				Navire* cible = running->GetNavire(index, j);
				for (int k = 0; k < cible->GetPos().size(); k++)
				{
					if (cible->GetPos()[k].x == i && cible->GetPos()[k].y == y)
					{
						cible->GetPos()[k].etat = EtatCase::Touche;
						if (cible->GetNavireType() == NavireType::SousMarin)
							((SousMarin*)cible)->Move(running, index);
						else if (cible->GetNavireType() == NavireType::Croiseur)
							((Croiseur*)cible)->GetTorpPos(this, running, index);
					}
				}
			}
		}
		i++;
	}
}
