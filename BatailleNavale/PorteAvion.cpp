#include "Jeu.h"

using namespace std;

PorteAvion::PorteAvion(bool isHoriz, int x, int y, int countdown) : Navire(NavireType::PorteAvion, isHoriz, x, y)
{
	this->countdown = countdown;
}

void PorteAvion::Init(Jeu* running, int index) {
	bool isPlaced = false;
	bool horiz = false;
	Pos temp;
	int input = -1;

	while (!isPlaced) {
		while (input < 0 || input > 1) {
			system("cls");
			cout << "\nConfiguration du porte-avion : \nHorizontale ou verticale ? 0 ou 1\n";
			cin >> input;
		}
		horiz = (input == 0) ? true : false;
		temp = running->SetNavPos();
		this->cases[0].x = temp.x;
		this->cases[0].y = temp.y;
		this->isHoriz = horiz;
		isPlaced = running->shipHasPlace(index, 4);
	}

	for (int i = 0; i < this->cases.size(); i++)
	{
		this->cases[i].x = (this->isHoriz) ? temp.x + i : temp.x;
		this->cases[i].y = (this->isHoriz) ? temp.y : temp.y + i;
		running->GetMap(index)[this->cases[i].y][this->cases[i].x] = 2;
	}
}

void PorteAvion::UseAbility(Jeu* running, int index)
{
	int input = -1;
	int input2 = -1;
	int count = (index == 0) ? this->count / 2 : this->count;
	int caseCount = running->GetNavire(index, input)->GetPos().size();

	if (this->countdown != 0) {
		while (input < 0 || input > count) {
			cout << "Veuillez selectionner le navire a reparer.\n";
			for (int i = (index == 1) ? this->count / 2 : 0; i < count; i++) {
				switch (running->GetNavire(index, i)->GetNavireType())
				{
				case NavireType::Torpilleur: cout << i << "." << " Torpilleur\n";
					break;
				case NavireType::SousMarin: cout << i << "." << " Sous-Marin\n";
					break;
				case NavireType::Croiseur: cout << i << "." << " Croiseur\n";
					break;
				case NavireType::PorteAvion: cout << i << "." << " Porte-Avion\n";
					break;
				}
			}
			cin >> input;
		}
		while (input2 < 0 || input > caseCount) {
			system("cls");
			cout << "Quel case de ce navire voulez-vous reparer ?\n";
			for (int i = 0; i < caseCount; i++) {
				cout << "Case N°" << i << " est ";
				switch (running->GetNavire(index, input)->GetPos()[i].etat) {
				case EtatCase::Cache: cout << "cache.\n";
					break;
				case EtatCase::Touche: cout << "touche.\n";
					break; 
				case EtatCase::ToucheCache: cout << "touche et cache.\n";
					break; 
				case EtatCase::Visible: cout << "visble.\n";
					break;
				}
				cin >> input2;
			}
		}
		running->GetNavire(index, input)->GetPos()[input2].etat = EtatCase::Visible;
		running->GetMap(index)[running->GetNavire(index, input)->GetPos()[input2].y][running->GetNavire(index, input)->GetPos()[input2].x] = 4;
	}
}
