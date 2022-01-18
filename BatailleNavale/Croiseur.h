#pragma once
#include "Navire.h"

class Torpilleur;
class Jeu;

class Croiseur :
    public Navire
{
 public:
     Croiseur();
     Croiseur(bool isHoriz, int x, int y);
     void Init(Jeu* running, int index);
     void UseAbility(Jeu* running, int index);
};

