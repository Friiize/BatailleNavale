#include "Jeu.h"

using namespace std;

PorteAvion::PorteAvion(bool isHoriz, int x, int y, int countdown) : Navire(NavireType::PorteAvion, isHoriz, x, y)
{
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
		isPlaced = running->shipHasPlace(index, this);
	}

	for (int i = 0; i < this->cases.size(); i++)
	{
		this->cases[i].x = (this->isHoriz) ? temp.x + i : temp.x;
		this->cases[i].y = (this->isHoriz) ? temp.y : temp.y + i;
		running->SetMapValue(index, this->cases[i].y, this->cases[i].x, 2);
	}
}

void PorteAvion::UseAbility(Jeu* running, int index)
{
	int input = -1;
	int input2 = -1;

	if (running->GetCountdown(index) == 0) {
		while (input < 0 || input > 5) {
			cout << "Veuillez selectionner le navire a reparer.\n";
			for (int i = 0; i < 5; i++) {
				switch (running->GetNavire(index, i)->GetNavireType())
				{
				case NavireType::Torpilleur:
					if (!running->GetNavire(index, i)->GetIsUnscathed())
						cout << i << "." << " Torpilleur\n";
					break;
				case NavireType::SousMarin:
					if (!running->GetNavire(index, i)->GetIsUnscathed())
						cout << i << "." << " Sous-Marin\n";
					break;
				case NavireType::Croiseur:
					if (!running->GetNavire(index, i)->GetIsUnscathed())
						cout << i << "." << " Croiseur\n";
					break;
				case NavireType::PorteAvion:
					if (!running->GetNavire(index, i)->GetIsUnscathed())
						cout << i << "." << " Porte-Avion\n";
					break;
				}
			}
			cin >> input;
		}
		int caseCount = running->GetNavire(index, input)->GetPos().size();
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
				case EtatCase::Visible: cout << "visible.\n";
					break;
				}
			}
			cin >> input2;
		}
		running->GetNavire(index, input)->SetEtatCase(input2, EtatCase::Visible);
		running->GetNavire(index, input)->CheckCases();
		running->SetMapValue(index, running->GetNavire(index, input)->GetPos()[input2].y, running->GetNavire(index, input)->GetPos()[input2].x, 4);
		running->SetCountdown(index, 5);
	}
}
