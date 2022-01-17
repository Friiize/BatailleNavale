#pragma once
#include "Navire.h"
class Croiseur :
    public Navire
{
 public:
     Croiseur();
     Croiseur(bool isHoriz, int x, int y);
     Pos GetTorpPos();
};

