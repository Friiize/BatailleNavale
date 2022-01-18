#pragma once
#include "Navire.h"

class Jeu;

class PorteAvion :
    public Navire
{
public:
    PorteAvion();
    PorteAvion(bool isHoriz, int x, int y, int countdown);
    void Init(Jeu* running, int index);
    void UseAbility(Jeu* running, int index);
};

