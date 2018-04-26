#include "game_of_life.h"
#include "ctime"

int game_of_life::slucajna_vrijednost()
{
	return rand() % (max - min + 1) + min;
}

void game_of_life::zamjena_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int life = 0;

			for (int k = -1; k < 2; k++)
			{
				for (int h = -1; h < 2; h++)
				{
					if ((i + k) == -1 || (i + k) == REDAKA || (j + h) == -1 || (j + h) == STUPACA || (k == 0 && h == 0))
					{
						continue;
					}

					life += generacija[i + k][j + h];

				}
			}



			if ((life < 2 || life > 3) && generacija[i][j])
			{
				_sljedeca_generacija[i][j] = false;
			}
			else if ((life == 2 || life == 3) && generacija[i][j])
			{
				_sljedeca_generacija[i][j] = true;
			}
			else if (generacija[i][j] == false && life == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			else
				_sljedeca_generacija[i][j] = false;
		}
	}

}

void game_of_life::crtanje_generacije_1()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int posto = slucajna_vrijednost();
			if (posto == 1)
			{
				generacija[i][j] = true;
				cout << "*";
			}
			else
			{
				generacija[i][j] = false;
				cout << "-";
			}
		}
		cout << endl;
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}
