#pragma once
#include "Navire.h"

class Torpilleur :
    public Navire
{
public:
    Torpilleur();
    Torpilleur(NavireType type, bool isHoriz, int x, int y);
    void Shoot(int x, int y);
};
