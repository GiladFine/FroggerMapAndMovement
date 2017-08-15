#ifndef C_MAP
#define C_MAP


#include <iostream>
#include <string>
#include <Windows.h>
#include "ConsolePrinter.h"

#define MAP_HEIGHT		50
#define MAP_WIDTH		100
#define BOUNDRY_CHAR	'#'
#define SPACE_CHAR		' '

using namespace std;

class Map{
private:
	char map[MAP_HEIGHT][MAP_WIDTH];
	int colors[MAP_HEIGHT][MAP_WIDTH];
	ConsolePrinter printer;
	Map() { init(); }
public:
	void init();
	char getMapAt(int x, int y) { return map[y][x]; }
	void setMapAt(int x, int y, char c) { map[y][x] = c; }
	int getColorsAt(int x, int y) { return colors[y][x]; }
	void setColorsAt(int x, int y, int color) { colors[y][x] = color; }
	void printMap();
	static Map& getInstance();
};

#endif //C_MAP