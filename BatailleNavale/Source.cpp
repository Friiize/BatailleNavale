#include "Header.h"
#include "Jeu.h"

using namespace std;

int main() {
	Jeu* running = new Jeu();
	running->init();
	((PorteAvion*) (running->GetNavire(0, 4)))->RepairCase(running, 0);
	return 0;
}