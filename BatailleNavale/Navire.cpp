#include "Navire.h"

using namespace std;

Navire::Navire(NavireType type, bool isHoriz, int x, int y)
{
	this->type = type;
	this->isHoriz = isHoriz;
	for (int i = 0; i < (int)this->type; i++)
		cases.push_back((isHoriz) ? Pos{ x + i, y, EtatCase::Cache } : Pos{ x, y + i, EtatCase::Cache });
	this->count++;
}

void Navire::SetIsHoriz(bool x)
{
	this->isHoriz = x;
}

void Navire::SetNavireType(NavireType x)
{
	this->type = x;
}

bool Navire::GetIsHoriz()
{
	return this->isHoriz;
}

NavireType Navire::GetNavireType()
{
	return this->type;
}

vector<Pos> Navire::GetPos()
{
	return cases;
}