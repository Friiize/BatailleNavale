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
	countdown[0] = 2;
	countdown[1] = 2;
}

void Jeu::Start() {
	for (int i = 0; i < 2; i++)
	{
		(i == 0) ? cout << "Navires du joueur 1\n" : cout << "Navires du joueur 2\n";
		system("pause");
		this->navires[i][0] = new Torpilleur(false, 0, 0);
		this->navires[i][0]->Init(this, i);
		this->navires[i][1] = new SousMarin(false, 0, 0);
		this->navires[i][1]->Init(this, i);
		this->navires[i][2] = new SousMarin(false, 0, 0);
		this->navires[i][2]->Init(this, i);
		this->navires[i][3] = new Croiseur(false, 0, 0);
		this->navires[i][3]->Init(this, i);
		this->navires[i][4] = new PorteAvion(false, 0, 0, 5);
		this->navires[i][4]->Init(this, i);
	}
}

int Jeu::GameLoop() {
	int player = 0;
	int winner = 0;
	while (winner == 0)
	{
		system("cls");
		afficherMaps(player);
		cout << "Tour du joueur " << player + 1 << endl;
		bool CanPlay = false;
		for (int i = 0; i < 5; i++)
			if (this->navires[player][i]->GetIsAlive())
				CanPlay = true;
		if (CanPlay)
			this->ShootTurn(player);
		else
			winner = (player == 0) ? 2 : 1;
		if (countdown[player] > 0)
			countdown[player]--;
		player = (player + 1) % 2;
		system("pause");
	}
	return winner;
}

void Jeu::ShootTurn(int index) {
	cout << "Quelle action voulez-vous faire ?" << endl; 
	int count = 1;
	cout << count++ << ". Tirer" << endl;
	for (int i = 0; i < 5; i++) {
		switch (this->GetNavire(index, i)->GetNavireType())
		{
		case NavireType::Torpilleur:
			if (this->GetNavire(index, i)->GetIsUnscathed())
				cout << count++ << ". " << GetAbilityNameFromNavireType(this->GetNavire(index, i)->GetNavireType()) << endl;
			break;
		case NavireType::PorteAvion:
			if (this->countdown[index] == 0)
				cout << count++ << ". " << GetAbilityNameFromNavireType(this->GetNavire(index, i)->GetNavireType()) << endl;
			break;
		}
	}
	int input = 0;
	while (input < 1 || input >= count)
		cin >> input;
	int x = 0, y = 0;
	switch (input)
	{
	case 1:
		cout << "Veuillez indiquer la colonne du tir" << endl;
		cin >> x;
		cout << "Veuillez indiquer la ligne du tir" << endl;
		cin >> y;
		switch (this->maps[(index + 1) % 2][y][x])
		{
		case 2: case 3: case 4: case 5: case 6: case 7:
			cout << "Le tir a atteint une cible" << endl;
			this->maps[(index + 1) % 2][y][x] = 3;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < this->navires[(index + 1) % 2][i]->GetPos().size(); j++)
				{
					if (this->navires[(index + 1) % 2][i]->GetPos()[j].x == x && this->navires[(index + 1) % 2][i]->GetPos()[j].y == y)
					{
						this->navires[(index + 1) % 2][i]->SetEtatCase(j, EtatCase::Touche);
						if (this->navires[(index + 1) % 2][i]->GetNavireType() == NavireType::SousMarin)
							this->navires[(index + 1) % 2][i]->UseAbility(this, (index + 1) % 2);
						this->navires[(index + 1) % 2][i]->CheckCases();
					}
				}
			}
			break;
		default:
			this->maps[(index + 1) % 2][y][x] = 1;
			break;
		}
		break;
	case 2:
		if (count == 3 && countdown[index] == 0)
		{
			bool used = false;
			int i = 0;
			while (i < 5 && !used)
			{
				if (this->GetNavire(index, i)->GetNavireType() == NavireType::PorteAvion)
				{
					this->GetNavire(index, i)->UseAbility(this, index);
					used = true;
				}
				i++;
			}
		}
		else
		{
			bool used = false;
			int i = 0;
			while (i < 5 && !used)
			{
				if (this->GetNavire(index, i)->GetNavireType() == NavireType::Torpilleur)
				{
					this->GetNavire(index, i)->UseAbility(this, (index + 1) % 2);
					used = true;
				}
				i++;
			}
		}
		break;
	case 3:
		bool used = false;
		int i = 0;
		while (i < 5 && !used)
		{
			if (this->GetNavire(index, i)->GetNavireType() == NavireType::PorteAvion)
			{
				this->GetNavire(index, i)->UseAbility(this, index);
				used = true;
			}
			i++;
		}
		break;
	}
}

/*void Jeu::init() {
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
}*/

int Jeu::GetMapCase(int index, int y, int x)
{
	return maps[index][y][x];
}

void Jeu::SetMapValue(int index, int y, int x, int value)
{
	this->maps[index][y][x] = value;
}

Navire* Jeu::GetNavire(int index, int indexNavire)
{
	return navires[index][indexNavire];
}

/*Navire*** Jeu::GetNavires() {
	return reinterpret_cast<Navire***>(navires);
}*/

int Jeu::GetCountdown(int index) {
	return countdown[index];
}

void Jeu::SetCountdown(int index, int x) {
	countdown[index] = x;
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
			case 1: case 6: case 7: display += "O"; break;
			case 3: display += "X"; break;
			case 4: display += "+"; break;
			default: display += "~"; break;
			}
			display += " ";
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
			case 3: case 5: case 7: display += "X"; break;
			case 2: case 4: case 6: display += "+"; break;
			default: display += "~"; break;
			}
			display += " ";
		}
		display += "\n";
	}
	cout << display;
}

void Jeu::afficherMaps(int index)
{
	afficherMapEnnemi((index + 1) % 2);
	cout << endl;
	afficherMapJoueur(index % 2);
}

bool Jeu::shipHasPlace(int index, Navire* navire)
{
	if (navire->GetIsHoriz())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < navire->GetPos().size() + 2; j++)
			{
				int y = navire->GetPos()[0].y - 1 + i;
				int x = navire->GetPos()[0].x - 1 + j;
				if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || maps[index][y][x] > 1 && maps[index][y][x] < 8)
					return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < navire->GetPos().size() + 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int y = navire->GetPos()[0].y - 1 + i;
				int x = navire->GetPos()[0].x - 1 + j;
				if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE || maps[index][y][x] > 1 && maps[index][y][x] < 8)
					return false;
			}
		}
	}
	return true;
}