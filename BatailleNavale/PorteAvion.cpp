#include "PorteAvion.h"

PorteAvion::PorteAvion(NavireType type, bool isHoriz, int x, int y, int countdown) : Navire(type, isHoriz, x, y)
{
	this->countdown = countdown;
}

void PorteAvion::RepairCase()
{

}
