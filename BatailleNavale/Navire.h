#pragma once
#include "Header.h"
#include "Jeu.h"

class Jeu;
class Navire
{
protected:
	bool isHoriz;
	NavireType type;
	std::vector<Pos> cases;
	static int count;

public:
	Navire();
	Navire(NavireType type, bool isHoriz, int x, int y);

	bool GetIsHoriz();
	NavireType GetNavireType();

	void SetIsHoriz(bool x);
	void SetNavireType(NavireType x);
	std::vector<Pos> GetPos();
	virtual void Init() = 0;
	virtual void Shoot(int y, int index, Jeu* running) = 0;
	virtual void Move(Jeu* running, int index) = 0;
	virtual void GetTorpPos(Torpilleur* cible, Jeu* running, int index) = 0;
	virtual void RepairCase(Jeu* running, int index) = 0;
};

