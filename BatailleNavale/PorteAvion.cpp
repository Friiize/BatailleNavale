#include "Jeu.h"

using namespace std;

PorteAvion::PorteAvion(bool isHoriz, int x, int y, int countdown) : Navire(NavireType::PorteAvion, isHoriz, x, y)
{
	this->countdown = countdown;
}

void PorteAvion::RepairCase(Jeu* running, int index)
{
	if (this->countdown != 0) {
		cout << "Veuillez selectionner le navire a reparer.\n";
		for (int i = 0; i < this->count; i++) {
			switch (running->GetNavire(index, i)->GetNavireType())
			{
			case NavireType::Torpilleur: cout << i << "." << " Torpilleur";
				break; 
			case NavireType::SousMarin : cout << i << "." << " Sous-Marin";
				break;
			case NavireType::Croiseur : cout << i << "." << " Croiseur";
				break;
			case NavireType::PorteAvion : cout << i << "." << " Porte-Avion";
				break;
			}
		}
	}
}
