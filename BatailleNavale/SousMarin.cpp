#include "SousMarin.h"

SousMarin::SousMarin(NavireType type, bool isHoriz, int x, int y) : Navire (type, isHoriz, x, y)
{
}

void SousMarin::Move(bool z, int x, int y)
{
	this->isHoriz = z;
	this->x = x;
	this->y = y;
}
