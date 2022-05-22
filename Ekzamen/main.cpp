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
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // получаем дескриптор
	INPUT_RECORD InputRecord; // используется для возвращения информации о входных сообщениях в консольном входном буфере
	DWORD Events; // unsigned long
	COORD coord; // для координат X, Y

	/*Запретить выделение консоли*/
	DWORD prev_mode;
	GetConsoleMode(hin, &prev_mode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));

	char map[9] = { '#', '#', '#', '#', '#', '#', '#', '#', '#' };
	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, SW_MAXIMIZE);
	int play1 = 0, play2 = 1,x = -1 , y = -1;
	int mapmose[3][3];
	int ch = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mapmose[i][j] = ch;
			ch++;
		}
	}


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
		x = -1; y = -1;
		SetConsoleMode(hin, ENABLE_MOUSE_INPUT); // разрешаем обработку мыши
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t Игра\n\t\t\t\t\t\t\t\t\t\t\t\t\t      Click to [#]" << endl;
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
			if (map[j] != '#' && map[j] == map[j + 1] && map[j] == map[j + 2])
			{
				goto Wins;
			}
		}
		// прверка вертикалей
		for (int j = 0; j < 3; j++)
		{
			if (map[j] != '#' && map[j] == map[j + 3] && map[j] == map[j + 6])
			{
				goto Wins;
			}
		}
		// проверка крестом
		if (map[0] != '#' && map[0] == map[4] && map[0] == map[8])
		{
			goto Wins;
		}
		if (map[2] != '#' && map[2] == map[4] && map[2] == map[6])
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
					map[j] = '#';
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
			if (map[j] != '#')
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
			}else {
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tError.....\t\t\t\t\t";
				Sleep(2000);
				ShowWindow(windowHandle, SW_HIDE);
				exit(0);
			}

		}


		// Есле игра не оконченна
			while (true)
			{
				ReadConsoleInput(hin, &InputRecord, 1, &Events);
				if (InputRecord.Event.MouseEvent.dwButtonState == MOUSE_WHEELED || InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED || InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
					coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
					break;
				}
			}
			switch (coord.X)
			{
			case 106:
				x = 0;
				break;
			case 114:
				x = 1;
				break;
			case 122:
				x = 2;
				break;
			default:
				continue;
			}
			switch (coord.Y)
			{
			case 20:
				y = 0;
				break;
			case 21:
				y = 1;
				break;
			case 22:
				y = 2;
				break;
			default:
				continue;
			}
		if (map[mapmose[y][x]] != '#')
		{
			i--;
			cout << "Поле не доступно";
			Sleep(500);
			system("cls");
			continue;
		}

		map[mapmose[y][x]] = sin;
		std::swap(play1, play2);
		std::system("cls");
	}

	


	return 0;
}