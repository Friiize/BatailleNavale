#pragma once
#include <iostream>
#include <time.h>

struct Pos {
	int x;
	int y;
};

enum class NavireType
{
	SousMarin = 3, PorteAvion = 5, Torpilleur = 2, Croiseur=4
};