#include "Jeu.h"

using namespace std;

SousMarin::SousMarin(bool isHoriz, int x, int y) : Navire (NavireType::SousMarin, isHoriz, x, y)
{
	hasMoved = false;
}

void SousMarin::Init() {
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
		temp = this->SetNavPos();
		this->x = temp.x;
		this->y = temp.y;
		this->isHoriz = horiz;
		isPlaced = this->shipHasPlace(i, 4);
	}
}

void SousMarin::Move(Jeu *running, int index)
{
	bool z;
	int x, y;
	/*if (!hasMoved)
		for (int i = 0; i < this->cases.size(); i++)
			running->GetMaps(index)[this->cases[i].y][this->cases[i].x] = 0;*/
	while (!hasMoved)
	{
		cin >> z;
		cin >> x;
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
					cases[i].x = x + i;
					cases[i].y = y;
				}
				else
				{
					cases[i].x = x;
					cases[i].y = y + 1;
				}
				cases[i].etat = (cases[i].etat == EtatCase::Touche || cases[i].etat == EtatCase::ToucheCache) ? EtatCase::ToucheCache : EtatCase::Cache;
			}
			hasMoved = running->shipHasPlace(index, indexNavire);
		}
	}
}
