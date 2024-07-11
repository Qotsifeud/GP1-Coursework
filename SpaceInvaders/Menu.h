#pragma once
#include <iostream>
#include <conio.h> // for _getch()

using namespace std;

class Menu
{
public:
	Menu() {}
	~Menu() {}
	void run();
	void gameOver();

	int choice;

private:
};

