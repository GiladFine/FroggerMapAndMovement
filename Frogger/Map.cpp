#include "Map.h"


void Map::init()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		setMapAt(0, i, BOUNDRY_CHAR);
		setMapAt(MAP_WIDTH - 1, i, BOUNDRY_CHAR);
	}
	for (int i = 1; i < MAP_WIDTH - 1; ++i)
	{
		setMapAt(i, 0, BOUNDRY_CHAR);
		setMapAt(i, MAP_HEIGHT - 1, BOUNDRY_CHAR);
	}
	for (int i = 1; i < MAP_HEIGHT - 1; ++i)
	{
		for (int j = 1; j < MAP_WIDTH - 1; ++j)
		{
			setMapAt(j, i, SPACE_CHAR);
		}
	}

	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (i == 1 || i == 2)
			{
				if ((j >= 6 && j <= 13) || (j >= 22 && j <= 29) || (j >= 38 && j <= 45) || (j >= 54 && j <= 61) || (j >= 70 && j <= 77) || (j >= 86 && j <= 93))
					setColorsAt(j, i, GREEN_ON_BLUE);
				else if ((j != MAP_WIDTH - 1) && (j != 0))
					setColorsAt(j, i, GREEN_ON_RED);
				else
					setColorsAt(j, i, DARK_GREEN);
			}
			else if ((i == 25 || i == 26 || i == 47 || i == 48) && (j != 0) && (j != MAP_WIDTH - 1))
				setColorsAt(j, i, GREEN_ON_RED);
			else
				setColorsAt(j, i, DARK_GREEN);
		}
	}
}

void Map::printMap()
{
	system("cls");
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
				printer.drawChar(j, i, map[i][j],colors[i][j]);
		}
		cout << endl;
	}
}

Map& Map::getInstance()
{
	static Map instance;
	return instance;
}