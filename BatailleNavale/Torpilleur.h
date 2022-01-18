#pragma once
#include "Navire.h"
#include "Jeu.h"

class Torpilleur :
    public Navire
{
public:
    Torpilleur();
    Torpilleur(bool isHoriz, int x, int y);
    void Shoot(int y, int index, Jeu* running);
};

