#include "Croiseur.h"

Croiseur::Croiseur(bool isHoriz, int x, int y) : Navire(NavireType::Croiseur, isHoriz, x, y)
{
}

Pos Croiseur::GetTorpPos()
{
	return Pos();
}
