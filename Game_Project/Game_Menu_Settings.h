#pragma once
#include <iostream>
#include <string>
#include <vector>

void setcur(int x, int y)//screan clear
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void game_over_print()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t 000   1001  1     1  0000" << endl;
	cout << "\t\t\t\t\t\t\t\t1      0  0  10   01  1   " << endl;
	cout << "\t\t\t\t\t\t\t\t1  01  1001  1 0 0 1  100 " << endl;
	cout << "\t\t\t\t\t\t\t\t1   1  1  1  1  1  1  1   " << endl;
	cout << "\t\t\t\t\t\t\t\t 000   1  1  1     1  0000" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t 000   0  0  0000  100  " << endl;
	cout << "\t\t\t\t\t\t\t\t1   1  1  1  1     1  0 " << endl;
	cout << "\t\t\t\t\t\t\t\t1   1  1  1  100   100  " << endl;
	cout << "\t\t\t\t\t\t\t\t1   1  1  1  1     1  0 " << endl;
	cout << "\t\t\t\t\t\t\t\t 000    00   0000  1   0" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
void game_start_time()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t000000" << endl;
	cout << "\t\t\t\t\t\t\t\t      0" << endl;
	cout << "\t\t\t\t\t\t\t\t      0" << endl;
	cout << "\t\t\t\t\t\t\t\t 00000 " << endl;
	cout << "\t\t\t\t\t\t\t\t      0" << endl;
	cout << "\t\t\t\t\t\t\t\t      0" << endl;
	cout << "\t\t\t\t\t\t\t\t000000" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(1000);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t 000000" << endl;
	cout << "\t\t\t\t\t\t\t\t       0" << endl;
	cout << "\t\t\t\t\t\t\t\t       0" << endl;
	cout << "\t\t\t\t\t\t\t\t 000000" << endl;
	cout << "\t\t\t\t\t\t\t\t0      " << endl;
	cout << "\t\t\t\t\t\t\t\t0      " << endl;
	cout << "\t\t\t\t\t\t\t\t 000000" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(1000);
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t      00" << endl;
	cout << "\t\t\t\t\t\t\t\t     000" << endl;
	cout << "\t\t\t\t\t\t\t\t    0 00" << endl;
	cout << "\t\t\t\t\t\t\t\t      00" << endl;
	cout << "\t\t\t\t\t\t\t\t      00" << endl;
	cout << "\t\t\t\t\t\t\t\t      00" << endl;
	cout << "\t\t\t\t\t\t\t\t      00" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(1000);
	system("cls");
}