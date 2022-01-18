#pragma once
#include "Navire.h"
#include "Jeu.h"

class SousMarin :
    public Navire
{
private:
    bool hasMoved;

public:
    SousMarin();
    SousMarin(bool isHoriz, int x, int y);
    void Move(Jeu* running, int index);
};

