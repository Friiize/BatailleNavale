#include "Navire.h"

Navire::Navire(NavireType type, bool isHoriz, int x, int y)
{
	this->type = type;
	this->isHoriz = isHoriz;
	this->x = x;
	this->y = y;
}

void Navire::SetIsHoriz(bool x)
{
	this->isHoriz = x;
}

void Navire::SetNavireType(NavireType x)
{
	this->type = x;
}

void Navire::SetX(int x)
{
	this->x = x;
}

void Navire::SetY(int y)
{
	this->y = y;
}

bool Navire::GetIsHoriz()
{
	return this->isHoriz;
}

NavireType Navire::GetNavireType()
{
	return this->type;
}

int Navire::GetPos()
{
	return this->x, this->y;
}
