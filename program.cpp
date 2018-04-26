#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
#include "ctime"
using namespace std;

int main() {
	game_of_life the_game;
	srand(time(nullptr));

	the_game.crtanje_generacije_1();

	bool dalje;
	cout << "Dalje (1/0): ";
	cin >> dalje;
	while (dalje)
	{
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		the_game.zamjena_generacija();

		cout << "Dalje (1/0): ";
		cin >> dalje;
	}

	return 0;
}
