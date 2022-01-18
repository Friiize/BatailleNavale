#include "Jeu.h"

using namespace std;

int main() {
	Jeu* running = new Jeu();
	running->Start();
	int winner = running->GameLoop();
	cout << "Le joueur " << winner << "a gagne.";
	system("pause");
	return 0;
}

string GetAbilityNameFromNavireType(NavireType type)
{
	switch (type)
	{
		case NavireType::Torpilleur: return "Torpiller une colonne";
		case NavireType::PorteAvion: return "Soigner un navire";
		default: return "Erreur";
	}
}