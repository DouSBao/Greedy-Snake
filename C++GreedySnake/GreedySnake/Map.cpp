#include "Map.h"

Map::Map(tool::sqrSize pos, COLORREF color)
{
	mapColor = color;
	mapSize.x = pos.x;
	mapSize.y = pos.y;
}

Edge::Edge(int length) : edgeLength(length)
{

}

Game::Game(tool::sqrSize pos, int length, COLORREF color) : Map(pos, color), Edge(length)
{
	initWindow();
	setfillcolor(RGB(GetRValue(color) + 15, GetGValue(color) + 15, GetBValue(color) + 15));
	solidrectangle(length, length, mapSize.x - length, mapSize.y - length);
}

const tool::sqrSize& Game::getSize()
{
	return mapSize;
}

COLORREF Game::getColor()
{
	return mapColor;
}

int Game::getEdgeLength()
{
	return edgeLength;
}

void Game::initWindow()
{
	initgraph(mapSize.x, mapSize.y);
	setbkcolor(mapColor);
	cleardevice();
}