#include "Jeu.h"

using namespace std;

int Navire::count = 0;

Navire::Navire(NavireType type, bool isHoriz, int x, int y)
{
	this->type = type;
	this->isHoriz = isHoriz;
	for (int i = 0; i < (int)this->type; i++)
		this->cases.push_back((isHoriz) ? Pos{ x + i, y, EtatCase::Cache } : Pos{ x, y + i, EtatCase::Cache });
	this->isAlive = true;
	this->isUnscathed = true;
	this->count++;
}

void Navire::CheckCases()
{
	isAlive = false;
	isUnscathed = true;
	for (int i = 0; i < cases.size(); i++)
	{
		if (cases[i].etat == EtatCase::Cache || cases[i].etat == EtatCase::Visible)
			isAlive = true;
		else
			isUnscathed = false;
	}
}

void Navire::SetEtatCase(int index, EtatCase etat)
{
	this->cases[index].etat = etat;
}

EtatCase Navire::GetEtatCase(int index)
{
	return this->cases[index].etat;
}

void Navire::SetIsHoriz(bool x)
{
	this->isHoriz = x;
}

void Navire::SetIsUnscathed(bool x)
{
	this->isUnscathed = x;
}

void Navire::SetNavireType(NavireType x)
{
	this->type = x;
}

bool Navire::GetIsHoriz()
{
	return this->isHoriz;
}

bool Navire::GetIsAlive()
{
	return this->isAlive;
}

bool Navire::GetIsUnscathed()
{
	return this->isUnscathed;
}

NavireType Navire::GetNavireType()
{
	return this->type;
}

vector<Pos> Navire::GetPos()
{
	return this->cases;
}