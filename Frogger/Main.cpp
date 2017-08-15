#include <iostream>
#include <conio.h>
#include "ConsolePrinter.h"
#include "Frog.h"
#include "Map.h"

#define LEFT_ARROW		75
#define RIGHT_ARROW		77
#define UP_ARROW		72
#define DOWN_ARROW		80

using namespace std;


void main()
{
	Frog f(3, 1);
	ConsolePrinter printer;
	Map map = Map::getInstance();
	char action;
	
	map.printMap();
	f.drawFrog();
	while (true)
	{
		printer.goToCoords(200, 200);
		action = _getch();
		switch (action)
		{
		case LEFT_ARROW:
			if (f.getHeadCoords().X != 3)
				f.moveLeft();
			break;
		case RIGHT_ARROW:
			if (f.getHeadCoords().X != 95)
				f.moveRight();
			break;
		case UP_ARROW:
			if (f.getHeadCoords().Y != 1)
				f.moveUp();
			break;
		case DOWN_ARROW:
			if (f.getHeadCoords().Y != 47)
				f.moveDown();
			break;
		}
	}
	system("pause");
}