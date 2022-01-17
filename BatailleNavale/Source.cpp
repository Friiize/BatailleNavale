#include "Header.h"
#include "Navire.h"
#include "Croiseur.h"
#include "PorteAvion.h"
#include "SousMarin.h"
#include "Torpilleur.h"
#include "Jeu.h"

using namespace std;

void initGame(Jeu* running) {
	int input = 0;
	bool horiz = false;
	int x, y = 0;

	for (int i = 0; i < 2; i++)
	{
		(i == 0) ? cout << "Navires du joueur 1" : cout << "Navires du joueur 2";
		system("pause");

		system("cls");
		while (input < 1 && input > 10) {
			cout << "\nConfiguration du torpilleur : \nHorizontale ou verticale ? 0 ou 1";
			cin input;
		}
		horiz = (input == 0) ? false : true;

		while (input < 1 && input > 10) {
			cout << "\nPosition en X ? entre 1 et 10";
			cin input;
		}
		x = input;
		while (input < 1 && input > 10) {
			cout << "\nPosition en Y ? entre 1 et 10";
			cin input;
		}
		y = input;
		running->navires[i][0] = new Torpilleur(horiz, x, y);

		system("cls");
		while (input < 1 && input > 10) {
			cout << "\nConfiguration du premier sous-marin : \nHorizontale ou verticale ? 0 ou 1";
			cin input;
		}
		horiz = (input == 0) ? false : true;

		while (input < 1 && input > 10) {
			cout << "\nPosition en X ? entre 1 et 10";
			cin input;
		}
		x = input;
		while (input < 1 && input > 10) {
			cout << "\nPosition en Y ? entre 1 et 10";
			cin input;
		}
		y = input;
		running->navires[i][1] = new SousMarin(horiz, x, y);

		system("cls");
		while (input < 1 && input > 10) {
			cout << "\nConfiguration du second sous-marin : \nHorizontale ou verticale ? 0 ou 1";
			cin input;
		}
		horiz = (input == 0) ? false : true;

		while (input < 1 && input > 10) {
			cout << "\nPosition en X ? entre 1 et 10";
			cin input;
		}
		x = input;
		while (input < 1 && input > 10) {
			cout << "\nPosition en Y ? entre 1 et 10";
			cin input;
		}
		y = input;
		running->navires[i][2] = new SousMarin(horiz, x, y);

		system("cls");
		while (input < 1 && input > 10) {
			cout << "\nConfiguration du croiseur : \nHorizontale ou verticale ? 0 ou 1";
			cin input;
		}
		horiz = (input == 0) ? false : true;

		while (input < 1 && input > 10) {
			cout << "\nPosition en X ? entre 1 et 10";
			cin input;
		}
		x = input;
		while (input < 1 && input > 10) {
			cout << "\nPosition en Y ? entre 1 et 10";
			cin input;
		}
		y = input;
		running->navires[i][3] = new Croiseur(horiz, x, y);

		system("cls");
		while (input < 1 && input > 10) {
			cout << "\nConfiguration du porte-avion : \nHorizontale ou verticale ? 0 ou 1";
			cin input;
		}
		horiz = (input == 0) ? false : true;

		while (input < 1 && input > 10) {
			cout << "\nPosition en X ? entre 1 et 10";
			cin input;
		}
		x = input;
		while (input < 1 && input > 10) {
			cout << "\nPosition en Y ? entre 1 et 10";
			cin input;
		}
		y = input;
		running->navires[i][4] = new PorteAvion(horiz, x, y);
	}
}

int main() {
	Jeu* running = new Jeu();
	initGame(running);

	return 0;
}