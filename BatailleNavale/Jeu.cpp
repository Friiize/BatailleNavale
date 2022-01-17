#include "Jeu.h"

using namespace std;

jeu::jeu()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			maps[0][i][j] = 0;
			maps[1][i][j] = 0;
		}
	}
}

void jeu::afficherMapEnnemi(int index)
{
	string display = "";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (maps[index][i][j])
			{
			case 1: display += "O"; break;
			case 3: display += "×"; break;
			case 4: display += "+"; break;
			default: display += "~"; break;
			}
		}
		display += "\n";
	}
	cout << display;
}

void jeu::afficherMapJoueur(int index)
{
	string display = "";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (maps[index][i][j])
			{
			case 1: display += "O"; break;
			case 3: case 5: display += "×"; break;
			case 2: case 4: display += "+"; break;
			default: display += "~"; break;
			}
		}
		display += "\n";
	}
	cout << display;
}

void jeu::afficherMaps(int index)
{
	afficherMapEnnemi(index + 1 % 2);
	afficherMapJoueur(index % 2);
}