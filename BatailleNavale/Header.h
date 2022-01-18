#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <string>

#define MAP_SIZE 12

enum class EtatCase
{
	Cache = 1,
	Touche = 2,
	ToucheCache = 3,
	Visible = 4
};

struct Pos {
	int x;
	int y;
	EtatCase etat;
};

enum class NavireType
{
	SousMarin = 3,
	PorteAvion = 5,
	Torpilleur = 2,
	Croiseur=4
};

std::string GetAbilityNameFromNavireType(NavireType type);