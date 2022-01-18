#pragma once
#include "Header.h"

class Jeu;

class Navire
{
protected:
	bool isAlive;
	bool isHoriz;
	NavireType type;
	std::vector<Pos> cases;
	static int count;

public:
	Navire();
	Navire(NavireType type, bool isHoriz, int x, int y);

	bool GetIsHoriz();
	bool GetIsAlive();
	NavireType GetNavireType();

	void CheckAlive();
	void SetIsHoriz(bool x);
	void SetNavireType(NavireType x);
	std::vector<Pos> GetPos();
	virtual void UseAbility(Jeu* running, int index) = 0;
};

