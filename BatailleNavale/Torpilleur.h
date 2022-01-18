#pragma once
#include "Navire.h"

class Jeu;

class Torpilleur :
    public Navire
{
public:
    Torpilleur();
    Torpilleur(bool isHoriz, int x, int y);
    void Shoot(int y, int index, Jeu* running);
};

