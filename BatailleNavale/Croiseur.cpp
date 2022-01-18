#include "Jeu.h"

using namespace std;

Croiseur::Croiseur(bool isHoriz, int x, int y) : Navire(NavireType::Croiseur, isHoriz, x, y)
{
}

void Croiseur::Init(Jeu* running, int index) {
	bool isPlaced = false;
	bool horiz = false;
	Pos temp;
	int input = -1;

	while (!isPlaced) {
		while (input < 0 || input > 1) {
			system("cls");
			cout << "\nConfiguration du croiseur : \nHorizontale ou verticale ? 0 ou 1\n";
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

void Croiseur::UseAbility(Jeu* running, int index)
{
	srand(time(NULL));
	cout << "Le croiseur recherche le torpilleur" << endl;
	Navire* cible = NULL;
	for (int i = 0; i < 5; i++)
		if (running->GetNavire(index, i)->GetNavireType() == NavireType::Torpilleur)
			cible = running->GetNavire(index, i);
	int random = rand() % cible->GetPos().size();
	if (cible->GetPos()[random].etat == EtatCase::Cache)
	{
		cible->SetEtatCase(random, EtatCase::Visible);
		running->SetMapValue(index, cible->GetPos()[random].y, cible->GetPos()[random].x, 4);
	}
	else if (cible->GetPos()[random].etat == EtatCase::ToucheCache)
	{
		cible->SetEtatCase(random, EtatCase::Touche);
		running->SetMapValue(index, cible->GetPos()[random].y, cible->GetPos()[random].x, 3);
	}
}
