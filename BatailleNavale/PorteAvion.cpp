#include "PorteAvion.h"

PorteAvion::PorteAvion(bool isHoriz, int x, int y, int countdown) : Navire(NavireType::PorteAvion, isHoriz, x, y)
{
	this->countdown = countdown;
}

void PorteAvion::RepairCase()
{

}
