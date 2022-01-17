#include "SousMarin.h"

SousMarin::SousMarin(NavireType type, bool isHoriz, int x, int y) : Navire (type, isHoriz, x, y)
{
}

int SousMarin::Move()
{
	srand(time(NULL));
	int cases = 5;
	bool dir = (rand() % 2 == 0) ? false : true;
	int x = rand() % cases + 1;
	cases -= x;
	int y = rand() % cases + 1;

	return x, y;
}
