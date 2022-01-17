#include "SousMarin.h"

SousMarin::SousMarin(bool isHoriz, int x, int y) : Navire (NavireType::SousMarin, isHoriz, x, y)
{
}

void SousMarin::Move(bool z, int x, int y)
{
	this->isHoriz = z;
	this->x = x;
	this->y = y;
}
