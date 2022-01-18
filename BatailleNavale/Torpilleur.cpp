#include "Jeu.h"

using namespace std;

Torpilleur::Torpilleur(bool isHoriz, int x, int y) : Navire(NavireType::Torpilleur, isHoriz, x, y)
{
}

void Torpilleur::UseAbility(Jeu* running, int index)
{
	int y = 0;
	cout << "Sur quelle colonne voulez-vous lancer votre torpille ? Choisissez une colonne entre 1 et 10" << endl;
	while (y < 1 || y > 10)
		cin >> y;
	int i = 1;
	bool hit = false;
	while (i < 11 && !hit)
	{
		if (running->GetMap(index)[y][i] != 0 || running->GetMap(index)[y][i] != 1)
		{
			hit = true;
			running->GetMap(index)[y][i] = 3;
			for (int j = 0; j < 5; j++)
			{
				Navire* cible = running->GetNavire(index, j);
				for (int k = 0; k < cible->GetPos().size(); k++)
				{
					if (cible->GetPos()[k].x == i && cible->GetPos()[k].y == y)
					{
						cible->GetPos()[k].etat = EtatCase::Touche;
						cible->CheckAlive();
						if (cible->GetNavireType() == NavireType::SousMarin)
							cible->UseAbility(running, index);
						else if (cible->GetNavireType() == NavireType::Croiseur)
							cible->UseAbility(running, index);
					}
				}
			}
		}
		i++;
	}
}
