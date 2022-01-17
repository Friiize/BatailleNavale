#pragma once
#include "Navire.h"
class SousMarin :
    public Navire
{
public:
    SousMarin();
    SousMarin(bool isHoriz, int x, int y);
    void Move(bool z, int x, int y);
};

