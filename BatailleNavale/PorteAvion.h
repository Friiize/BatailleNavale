#pragma once
#include "Navire.h"

class PorteAvion :
    public Navire
{
private:
    int countdown;
public:
    PorteAvion();
    PorteAvion(bool isHoriz, int x, int y, int countdown);
    void RepairCase();
};

