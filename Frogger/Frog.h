#ifndef C_FROG
#define C_FROG


#include <iostream>
#include <string>
#include <Windows.h>
#include "ConsolePrinter.h"
#include "Map.h"

#define HEAD_HEIGHT			2
#define HEAD_WIDTH			2
#define EYE_CHAR			254
#define LEFT_UP_LEG_CHAR	192
#define LEFT_DOWN_LEG_CHAR	218
#define RIGHT_UP_LEG_CHAR	217
#define RIGHT_DOWN_LEG_CHAR	191

using namespace std;

class Frog{
private:
	COORD headCoords;
	COORD leftUpLegCoords;
	COORD leftDownLegCoords;
	COORD rightUpLegCoords;
	COORD rightDownLegCoords;
	ConsolePrinter printer;
public:
	Frog();
	Frog(COORD head);
	Frog(int x, int y);
	void setCoords(COORD head);
	void setCoords(int x, int y);
	COORD getHeadCoords() { return headCoords; }
	void drawFrog();
	void deleteFrog();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	
};

#endif //C_FROG