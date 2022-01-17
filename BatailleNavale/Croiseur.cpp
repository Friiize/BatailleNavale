#include "Croiseur.h"

Croiseur::Croiseur(NavireType type, bool isHoriz, int x, int y) : Navire(type, isHoriz, x, y)
{
}

Pos Croiseur::GetTorpPos()
{
	return Pos();
}
