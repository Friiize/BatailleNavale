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
     void Init();
     void GetTorpPos(Torpilleur* cible, Jeu* running, int index);
};

