#include "ConsolePrinter.h"

void ConsolePrinter::setColor(int num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

void ConsolePrinter::goToCoords(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void ConsolePrinter::goToCoords(COORD coord) {
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, coord);
}


void ConsolePrinter::drawRect(COORD coord, int width, int height, int color)
{
	setColor(color);
	goToCoords(coord);
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			drawChar(coord.X + i, coord.Y + j, ' ', color);
		}
	}
}

void ConsolePrinter::drawChar(COORD coord, char c, int color)
{
	setColor(color);
	goToCoords(coord);
	cout << c;
}

void ConsolePrinter::drawChar(int x, int y, char c, int color)
{
	setColor(color);
	goToCoords(x, y);
	cout << c;
}

void ConsolePrinter::drawString(COORD coord, string str, int color)
{
	setColor(color);
	goToCoords(coord);
	cout << str;
}

void ConsolePrinter::drawString(int x, int y, string str, int color)
{
	setColor(color);
	goToCoords(x, y);
	cout << str;
}