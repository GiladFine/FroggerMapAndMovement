#ifndef C_ConsolePrinter
#define C_ConsolePrinter


#include <iostream>
#include <string>
#include <Windows.h>

#define DARK_GREEN			2
#define GRAY				7
#define GREEN				10
#define GREEN_ON_RED		66
#define GREEN_ON_BLUE		146

using namespace std;

class ConsolePrinter{
private:

public:
	void setColor(int num);
	void goToCoords(COORD coord);
	void goToCoords(int x, int y);
	void drawRect(COORD coord, int width, int height, int color = GRAY);
	void drawChar(COORD coord, char c, int color = GRAY);
	void drawChar(int x, int y, char c, int color = GRAY);
	void drawString(COORD coord, string str, int color = GRAY);
	void drawString(int x, int y, string str, int color = GRAY);
};

#endif //C_ConsolePrinter