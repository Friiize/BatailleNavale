#include "Jeu.h"

using namespace std;

Torpilleur::Torpilleur(bool isHoriz, int x, int y) : Navire(NavireType::Torpilleur, isHoriz, x, y)
{
	isUnscathed = true;
}

void Torpilleur::Init(Jeu* running, int index) {
	bool isPlaced = false;
	bool horiz = false;
	Pos temp;
	int input = -1;

	while (!isPlaced) {
		while (input < 0 || input > 1) {
			system("cls");
			cout << "\nConfiguration du torpilleur : \nHorizontale ou verticale ? 0 ou 1\n";
			cin >> input;
		}
		horiz = (input == 0) ? true : false;
		temp = running->SetNavPos();
		this->cases[0].x = temp.x;
		this->cases[0].y = temp.y;
		this->isHoriz = horiz;
		isPlaced = running->shipHasPlace(index, 4);
	}

	for (int i = 0; i < this->cases.size(); i++)
	{
		this->cases[i].x = (this->isHoriz) ? temp.x + i : temp.x;
		this->cases[i].y = (this->isHoriz) ? temp.y : temp.y + i;
		running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 2;
	}
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
