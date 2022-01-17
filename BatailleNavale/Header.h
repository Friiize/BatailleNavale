#pragma once
#include <iostream>
#include <time.h>

#define MAP_SIZE 12

struct Pos {
	int x;
	int y;
};

enum class NavireType
{
	SousMarin = 3, PorteAvion = 5, Torpilleur = 2, Croiseur=4
};