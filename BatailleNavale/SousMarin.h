#pragma once
#include "Navire.h"
class SousMarin :
    public Navire
{
public:
    SousMarin();
    SousMarin(NavireType type, bool isHoriz, int x, int y);
    int Move();
};

