#include<iostream>
using namespace std;

int sudoku[9][9] = { { 5,3,0,0,7,0,0,0,0 } ,{ 6,0,0,1,9,5,0,0,0 } ,{ 0,9,8,0,0,0,0,6,0 } ,{ 8,0,0,0,6,0,0,0,3 } ,{ 4,0,0,8,0,3,0,0,1 } ,{ 7,0,0,0,2,0,0,0,6 } ,{ 0,6,0,0,0,0,2,8,0 } ,{ 0,0,0,4,1,9,0,0,5 } ,{ 0,0,0,0,8,0,0,7,9 } };


int wiersz;
int kolumna;
int liczba;

bool CheckUniqRow()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (sudoku[i][j] == sudoku[i][j + 1])
            {
                return false;
            }
        }
    }
    return true;
}

bool CheckUniqCol()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == sudoku[i+1][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool CheckUniq()
{
    if (CheckUniqRow() == true && CheckUniqCol() == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    return CheckUniq();
}

void WypiszSudoku()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			cout << endl;
		}
		else{}

		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
			{
				cout << "  ";
			}
			else{}

			cout << sudoku[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

void DodajLiczbe(int wiersz, int kolumna, int liczba)
{
    sudoku[wiersz][kolumna] = liczba;
    
    WypiszSudoku();
    
    if (CheckUniq() == false)
    {
        cout << "Sudoku jeszcze nie jest poprawnie ukoncyona :(" << endl;
    }
    else
    {
        cout << "Sudoku jest poprawnie ukoncyona. Gratuluje :)" << endl;
    }
}

void Game()
{
	cout << "Wpisz numer wiersza: ";
	cin >> wiersz;

	if (wiersz >= 9 | wiersz < 0)
	{
		cout << "Wpisany wiersz nie moze byc wiekszy albo rowny 9 i mniejszy 0." << endl;
		Game();
	}

	cout << "Wpisz numer kolumny: ";
	cin >> kolumna;

	if (kolumna >= 9 | kolumna < 0)
	{
		cout << "Wpisana kolumna nie moze byc wieksza albo rowna 9 i mniejsza 0." << endl;
		Game();
	}

	cout << "Wpisz liczbe: ";
	cin >> liczba;

	if (liczba > 9 | liczba < 0)
	{
		cout << "Wpisana liczba nie moze byc wieksza 9 i mniejsza 0." << endl;
		Game();
	}

	cout << endl;
	DodajLiczbe(wiersz, kolumna, liczba);
	Game();
}

int main()
{
    
    WypiszSudoku();
    
    Game();
    
    return 0;
}
