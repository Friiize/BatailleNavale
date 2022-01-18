#pragma once
#include "Navire.h"

class Jeu;

class SousMarin :
    public Navire
{
private:
    bool hasMoved;

public:
    SousMarin();
    SousMarin(bool isHoriz, int x, int y);
    void Init();
    void UseAbility(Jeu* running, int index);
};

