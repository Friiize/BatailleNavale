#pragma once
#include "Navire.h"

class Jeu;

class PorteAvion :
    public Navire
{
private:
    int countdown;
public:
    PorteAvion();
    PorteAvion(bool isHoriz, int x, int y, int countdown);
    void Init();
    void RepairCase(Jeu* running, int index);
};

