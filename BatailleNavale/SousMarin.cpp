#include "Jeu.h"

using namespace std;

SousMarin::SousMarin(bool isHoriz, int x, int y) : Navire (NavireType::SousMarin, isHoriz, x, y)
{
	hasMoved = false;
}

void SousMarin::Init(Jeu* running, int index) {
	bool isPlaced = false;
	bool horiz = false;
	Pos temp;
	int input = -1;

	while (!isPlaced) {
		while (input < 0 || input > 1) {
			system("cls");
			cout << "\nConfiguration du sous-marin : \nHorizontale ou verticale ? 0 ou 1\n";
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
		running->GetMaps(index)[this->cases[i].y][this->cases[i].x] = 2;
	}
}

void SousMarin::UseAbility(Jeu *running, int index)
{
	bool z;
	int x, y;
	if (!this->hasMoved)
		for (int i = 0; i < this->cases.size(); i++)
			running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 0;
	while (!this->hasMoved)
	{
		cout << "Veuillez indiquer l'orientation de votre sous-marin :" << endl << "0. Horizontale" << endl << "1. Verticale" << endl;
		cin >> z;
		z = !z;
		cout << "Placez votre sous-marin sur les colonnes : choisissez entre 1 et 10." << endl;
		cin >> x;
		cout << "Placez votre sous-marin sur la colonne : choisissez entre 1 et 10." << endl;
		cin >> y;
		int indexNavire = -1;
		for (int j = 0; j < 5; j++)
			if (running->GetNavire(index, j) == this)
				indexNavire = j;
		if (indexNavire != -1)
		{
			this->isHoriz = z;
			for (int i = 0; i < 3; i++)
			{
				if (isHoriz)
				{
					this->cases[i].x = x + i;
					this->cases[i].y = y;
				}
				else
				{
					this->cases[i].x = x;
					this->cases[i].y = y + i;
				}
				this->cases[i].etat = (this->cases[i].etat == EtatCase::Touche || this->cases[i].etat == EtatCase::ToucheCache) ? EtatCase::ToucheCache : EtatCase::Cache;
			}
			this->hasMoved = running->shipHasPlace(index, indexNavire);
			if (this->hasMoved)
			{
				for (int i = 0; i < this->cases.size(); i++)
				{
					if (this->cases[i].etat == EtatCase::Cache)
					{
						if (running->GetMap(index)[this->cases[i].y][this->cases[i].x] == 0)
							running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 2;
						else if (running->GetMap(index)[this->cases[i].y][this->cases[i].x] == 1)
							running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 6;
					}
					else if (this->cases[i].etat == EtatCase::ToucheCache)
					{
						if (running->GetMap(index)[this->cases[i].y][this->cases[i].x] == 0)
							running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 5;
						else if (running->GetMap(index)[this->cases[i].y][this->cases[i].x] == 0)
							running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 7;
					}
				}
			}
		}
	}
}
