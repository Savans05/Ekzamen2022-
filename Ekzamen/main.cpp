#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include < stdlib.h >


using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	char map[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, SW_MAXIMIZE);
	int play1 = 0, play2 = 1;
	play1 = rand() % 2;
	if (play1 == 1)
	{
		play2 = 0;
	}
	else {
		play2 = 1;
	}
	int st,close;
	int vod = -1;
	char sin = ' ';
	for (int i = 0; true; i++)
	{
		int win = 0;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tКлетоки: \n\t\t\t\t\t\t\t\t\t\t\t\t(цыфра на клавиатуре это клетке в игре)\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  1   |   2   |   3   " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  4   |   5   |   6   " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  7   |   8   |   9   " << endl;

		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t Игра\n" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  " << map[0] << "   |   " << map[1] << "   |   " << map[2] << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  " << map[3] << "   |   " << map[4] << "   |   " << map[5] << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t  " << map[6] << "   |   " << map[7] << "   |   " << map[8] << endl;

		cout << "\t\t\t\t\t\t\t\t\t\t\t\tИгрок 1\t\t\t       Игрок 2";
		if (play1 == 1)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t  " << (char)24;
			sin = 'X';
		}
		else {
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         " << (char)24;
			sin = 'O';
		}
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
		// проверка горизонталей
		for (int j = 0; j < 9; j += 3)
		{
			if (map[j] != ' ' && map[j] == map[j + 1] && map[j] == map[j + 2])
			{
				goto Wins;
			}
		}
		// прверка вертикалей
		for (int j = 0; j < 3; j++)
		{
			if (map[j] != ' ' && map[j] == map[j + 3] && map[j] == map[j + 6])
			{
				goto Wins;
			}
		}
		// проверка крестом
		if (map[0] != ' ' && map[0] == map[4] && map[0] == map[8])
		{
			goto Wins;
		}
		if (map[2] != ' ' && map[2] == map[4] && map[2] == map[6])
		{
			goto Wins;
		}
		// При побидителе
		if (false)
		{
		Wins:
			cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t У нас есть побидитель!!!";
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t     Реванш?(Enter -> yes)(Esc -> no)";
			st = _getch();
			if (st == 27)
			{
				break;
			}
			else if (st == 13) {
				ShowWindow(windowHandle, SW_HIDE);
				system("cls");
				for (int j = 0; j < 9; j++)
				{
					map[j] = ' ';
				}
				i = 0;
				ShowWindow(windowHandle, SW_MAXIMIZE);
				continue;
			}
			else {
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tError.....\t\t\t\t\t";
				Sleep(2000);
				ShowWindow(windowHandle, SW_HIDE);
				exit(0);
			}
		}
		// При отсутсвие побидителя
		close = 0;
		for (int j = 0; j < 9; j++)
		{
			if (map[j]!=' ')
			{
				close++;
			}
		}
		if (close == 9)
		{
			cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t У нас ничья!!!";
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t     Ещё раз?(Enter -> yes)(Esc -> no)";
			st = _getch();
			if (st == 27)
			{
				break;
			}
			else if (st == 13) {
				ShowWindow(windowHandle, SW_HIDE);
				system("cls");
				for (int j = 0; j < 9; j++)
				{
					map[j] = ' ';
				}
				i = 0;
				ShowWindow(windowHandle, SW_MAXIMIZE);
				continue;
			}
			else {
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tError.....\t\t\t\t\t";
				Sleep(2000);
				ShowWindow(windowHandle, SW_HIDE);
				exit(0);
			}

		}


		// Есле игра не оконченна
		st = _getch();
		while (st < 49 && st > 57)
		{
			cout << "Поле отсуствует";
			st = _getch();
			cout << "\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \bv\b \b\b \b\b \b\b \b\b \b\b \b";
		}
		switch (st)
		{
		case 49:
			vod = 0;
			break;
		case 50:
			vod = 1;
			break;
		case 51:
			vod = 2;
			break;
		case 52:
			vod = 3;
			break;
		case 53:
			vod = 4;
			break;
		case 54:
			vod = 5;
			break;
		case 55:
			vod = 6;
			break;
		case 56:
			vod = 7;
			break;
		case 57:
			vod = 8;
			break;
		}
		if (map[vod] != ' ')
		{
			i--;
			cout << "Поле не доступно";
			Sleep(500);
			system("cls");
			continue;
		}
		map[vod] = sin;
		std::swap(play1, play2);
		std::system("cls");
	}

	return 0;
}