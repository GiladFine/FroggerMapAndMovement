#include "Frog.h"


Frog::Frog()
{
	setCoords(1, 0);
}

Frog::Frog(COORD head)
{
	setCoords(head);
}

Frog::Frog(int x, int y)
{
	setCoords(x, y);
}

void Frog::setCoords(COORD head)
{
	this->headCoords = head;

	--head.X;
	this->leftUpLegCoords = head;

	++head.Y;
	this->leftDownLegCoords = head;

	head.X += 3;
	this->rightDownLegCoords = head;

	--head.Y;
	this->rightUpLegCoords = head;
}

void Frog::setCoords(int x, int y)
{
	this->headCoords.X = x;
	this->headCoords.Y = y;

	--x;
	this->leftUpLegCoords.X = x;
	this->leftUpLegCoords.Y = y;

	++y;
	this->leftDownLegCoords.X = x;
	this->leftDownLegCoords.Y = y;

	x += 3;
	this->rightDownLegCoords.X = x;
	this->rightDownLegCoords.Y = y;

	--y;
	this->rightUpLegCoords.X = x;
	this->rightUpLegCoords.Y = y;
}



void Frog::drawFrog()
{

	//PRINT BODY
	printer.drawRect(headCoords, HEAD_WIDTH, HEAD_HEIGHT, BACKGROUND_GREEN);

	//PRINT EYES
	string str = char(EYE_CHAR) + string("") + char(EYE_CHAR);
	printer.drawString(headCoords, str, BACKGROUND_GREEN);

	int color = Map::getInstance().getColorsAt(headCoords.X, headCoords.Y);

	//PRINT LEFT-UP LEG
	printer.drawChar(leftUpLegCoords, LEFT_UP_LEG_CHAR, color);

	//PRINT LEFT-DOWN LEG
	printer.drawChar(leftDownLegCoords, LEFT_DOWN_LEG_CHAR, color);

	//PRINT RIGHT-DOWN LEG
	printer.drawChar(rightDownLegCoords, RIGHT_DOWN_LEG_CHAR, color);

	//PRINT RIGHT-UP LEG
	printer.drawChar(rightUpLegCoords, RIGHT_UP_LEG_CHAR, color);
	
}

void Frog::deleteFrog()
{
	Map map = Map::getInstance();
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			printer.drawChar(headCoords.X + j - 1, headCoords.Y + i, map.getMapAt(headCoords.X + j - 1, headCoords.Y + i), map.getColorsAt(headCoords.X + j - 1, headCoords.Y + i));
}

void Frog::moveUp()
{
	deleteFrog();
	setCoords(headCoords.X, headCoords.Y - 2);
	drawFrog();
}

void Frog::moveDown()
{
	deleteFrog();
	setCoords(headCoords.X, headCoords.Y + 2);
	drawFrog();
}

void Frog::moveRight()
{
	deleteFrog();
	setCoords(headCoords.X + 4, headCoords.Y);
	drawFrog();
}

void Frog::moveLeft()
{
	deleteFrog();
	setCoords(headCoords.X - 4, headCoords.Y);
	drawFrog();
}