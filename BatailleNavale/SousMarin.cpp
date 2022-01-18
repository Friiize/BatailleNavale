#include "SousMarin.h"

using namespace std;

SousMarin::SousMarin(bool isHoriz, int x, int y) : Navire (NavireType::SousMarin, isHoriz, x, y)
{
	hasMoved = false;
}

void SousMarin::Move(Jeu *running, int index)
{
	bool z;
	int x, y;
	if (!hasMoved)
		for (int i = 0; i < this->cases.size(); i++)
			running->GetMaps(index)[this->cases[i].y][this->cases[i].x] = 0;
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
