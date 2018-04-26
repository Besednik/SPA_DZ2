#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	int min = 1;
	int max = 4;

	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	int slucajna_vrijednost();

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
	void crtanje_generacije_1();
	void zamjena_generacija();
};

#endif
