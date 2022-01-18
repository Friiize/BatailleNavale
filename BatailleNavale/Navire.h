#pragma once
#include "Header.h"

class Navire
{
protected:
	bool isHoriz;
	NavireType type;
	std::vector<Pos> cases;
	int static count;

public:
	Navire();
	Navire(NavireType type, bool isHoriz, int x, int y);

	bool GetIsHoriz();
	NavireType GetNavireType();

	void SetIsHoriz(bool x);
	void SetNavireType(NavireType x);
	std::vector<Pos> GetPos();
};

