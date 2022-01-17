#pragma once
#include "Header.h"
class Navire
{
protected:
	bool isHoriz;
	NavireType type;
	int x, y;
public:
	Navire();
	Navire(NavireType type, bool isHoriz, int x, int y);

	bool GetIsHoriz();
	NavireType GetNavireType();
	int GetPos(); 

	void SetIsHoriz(bool x);
	void SetNavireType(NavireType x);
	void SetX(int x);
	void SetY(int y);
};

