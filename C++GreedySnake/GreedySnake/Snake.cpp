#include "Snake.h"

Head::Head(tool::position pos)
{
	this->headPos.x = pos.x;
	this->headPos.y = pos.y;
}

Tail::Tail(tool::position pos)
{
	this->tailPos.x = pos.x;
	this->tailPos.y = pos.y;
}

Body::Body(tool::sqrSize size, COLORREF color)
{
	this->bodySize.x = size.x;
	this->bodySize.y = size.y;
	bodyColor = color;
}

Snake::Snake(tool::sqrSize size, tool::position pos, COLORREF color) : Body(size, color), Head(pos), Tail(pos)
{
	setfillcolor(color);
	solidrectangle(pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2);
}

const tool::position& Snake::getHeadPosition()
{
	return headPos;
}

const tool::position& Snake::getTailPosition()
{
	return tailPos;
}

const tool::sqrSize& Snake::getBodySize()
{
	return bodySize;
}

std::list<tool::position> Snake::getSnakePosition()
{
	return snakePosition;
}

COLORREF Snake::getBodyColor()
{
	return bodyColor;
}