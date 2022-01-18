#pragma once
#include "Header.h"

class Jeu;

class Navire
{
protected:
	bool isAlive;
	bool isHoriz;
	bool isUnscathed;
	NavireType type;
	std::vector<Pos> cases;
	static int count;

public:
	Navire();
	Navire(NavireType type, bool isHoriz, int x, int y);

	bool GetIsHoriz();
	bool GetIsAlive();
	bool GetIsUnscathed();
	NavireType GetNavireType();

	void CheckAlive();
	void SetIsHoriz(bool x);
	void SetIsUnscathed(bool x);
	void SetNavireType(NavireType x);
	std::vector<Pos> GetPos();
	virtual void Init(Jeu* running, int index) = 0;
	virtual void UseAbility(Jeu* running, int index) = 0;
};

