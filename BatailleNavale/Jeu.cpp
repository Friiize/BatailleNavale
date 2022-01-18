#include "Jeu.h"
#include "Header.h"

using namespace std;

Jeu::Jeu()
{
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			maps[0][i][j] = 0;
			maps[1][i][j] = 0;
		}
	}
}

void Jeu::Start() {
	for (int i = 0; i < 2; i++)
	{
		(i == 0) ? cout << "Navires du joueur 1\n" : cout << "Navires du joueur 2\n";
		system("pause");
		this->GetNavires()[i][0] = new Torpilleur(false, 0, 0);
		this->GetNavires()[i][0]->Init(this, i);
		this->GetNavires()[i][1] = new SousMarin(false, 0, 0);
		this->GetNavires()[i][1]->Init(this, i);
		this->GetNavires()[i][2] = new SousMarin(false, 0, 0);
		this->GetNavires()[i][2]->Init(this, i);
		this->GetNavires()[i][3] = new Croiseur(false, 0, 0);
		this->GetNavires()[i][3]->Init(this, i);
		this->GetNavires()[i][4] = new PorteAvion(false, 0, 0, 5);
		this->GetNavires()[i][4]->Init(this, i);
	}
}

void Jeu::init() {
	int input = -1;
	bool horiz, isPlaced = false;
	Pos temp;

	for (int i = 0; i < 2; i++)
	{
		(i == 0) ? cout << "Navires du joueur 1\n" : cout << "Navires du joueur 2\n";
		system("pause");
		while (!isPlaced) {
			while (input < 0 || input > 1) {
				system("cls");
				cout << "\nConfiguration du torpilleur : \nHorizontale ou verticale ? 0 ou 1\n";
				cin >> input;
			}
			horiz = (input == 0) ? true : false;
			temp = this->SetNavPos();
			this->navires[i][0] = new Torpilleur(horiz, temp.x, temp.y);
			isPlaced = this->shipHasPlace(i, 0);
			if (!isPlaced)
				delete this->navires[i][0];
		}
		isPlaced = false;
		input = -1;
		while (!isPlaced) {
			while (input < 0 || input > 1) {
				system("cls"); 
				cout << "\nConfiguration du premier sous-marin : \nHorizontale ou verticale ? 0 ou 1\n";
				cin >> input;
			}
			horiz = (input == 0) ? true : false;
			temp = this->SetNavPos();
			this->navires[i][1] = new SousMarin(horiz, temp.x, temp.y);
			isPlaced = this->shipHasPlace(i, 1);
			if (!isPlaced)
				delete this->navires[i][1];
		}
		isPlaced = false;
		input = -1;
		while (!isPlaced) {
			while (input < 0 || input > 1) {
				system("cls"); 
				cout << "\nConfiguration du second sous-marin : \nHorizontale ou verticale ? 0 ou 1\n";
				cin >> input;
			}
			horiz = (input == 0) ? true : false;
			temp = this->SetNavPos();
			this->navires[i][2] = new SousMarin(horiz, temp.x, temp.y);
			isPlaced = this->shipHasPlace(i, 2);
			if (!isPlaced)
				delete this->navires[i][2];
		}
		isPlaced = false;
		input = -1;
		while (!isPlaced) {
			while (input < 0 || input > 1) {
				system("cls"); 
				cout << "\nConfiguration du croiseur : \nHorizontale ou verticale ? 0 ou 1\n";
				cin >> input;
			}
			horiz = (input == 0) ? true : false;
			temp = this->SetNavPos();
			this->navires[i][3] = new Croiseur(horiz, temp.x, temp.y);
			isPlaced = this->shipHasPlace(i, 3);
			if (!isPlaced)
				delete this->navires[i][3];
		}
		isPlaced = false;
		input = -1; 
		while (!isPlaced) {
			while (input < 0 || input > 1) {
				system("cls");
				cout << "\nConfiguration du porte-avion : \nHorizontale ou verticale ? 0 ou 1\n";
				cin >> input;
			}
			horiz = (input == 0) ? true : false;
			temp = this->SetNavPos();
			this->navires[i][4] = new PorteAvion(horiz, temp.x, temp.y, 5);
			isPlaced = this->shipHasPlace(i, 4);
			if (!isPlaced)
				delete this->navires[i][4];
		}
	}
}

int** Jeu::GetMap(int index)
{
	return reinterpret_cast<int**>(maps[index]);
}

Navire* Jeu::GetNavire(int index, int indexNavire)
{
	return navires[index][indexNavire];
}

Navire*** Jeu::GetNavires() {
	return reinterpret_cast<Navire***>(navires);
}

Pos Jeu::SetNavPos() {
	int input = 0, x = 0, y = 0;

	while (input < 1 || input > 11) {
		cout << "\nPosition en X ? entre 1 et 10\n";
		cin >> input;
	}
	x = input;
	input = 0;
	while (input < 1 || input > 11) {
		cout << "\nPosition en Y ? entre 1 et 10\n";
		cin >> input;
	}
	y = input;

	return Pos{x, y, EtatCase::Cache};
}

void Jeu::afficherMapEnnemi(int index)
{
	string display = "";
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
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

void Jeu::afficherMapJoueur(int index)
{
	string display = "";
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
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

void Jeu::afficherMaps(int index)
{
	afficherMapEnnemi(index + 1 % 2);
	afficherMapJoueur(index % 2);
}

bool Jeu::shipHasPlace(int index, int indexNavire)
{
	Navire placeholder = *navires[index][indexNavire];
	if (placeholder.GetIsHoriz())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < ((int)placeholder.GetNavireType()) + 2; j++)
			{
				int y = placeholder.GetPos()[0].y - 1 + i;
				int x = placeholder.GetPos()[0].x - 1 + j;
				if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || maps[index][y][x] > 1 && maps[index][y][x] < 6)
					return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < ((int)placeholder.GetNavireType()) + 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int y = placeholder.GetPos()[0].y - 1 + i;
				int x = placeholder.GetPos()[0].x - 1 + j;
				if (x < 0 || x >= MAP_SIZE - 1 || y < 0 || y >= MAP_SIZE - 1 || maps[index][y][x] > 1 && maps[index][y][x] < 6)
					return false;
			}
		}
	}
	return true;
}