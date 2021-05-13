#ifndef SNAKE_H
#define SNAKE_H

#include <graphics.h>
#include <list>
#include "Tool.h"

/* 
 * File: Snake.h
 * --------------------
 * Time: 11 May 2021
 * Coder: DouSBao
 * Function: Spawn snake
 */

class Head {
public:
	Head(tool::position pos);
	
protected:
	tool::position headPos;
};

class Tail {
public:
	Tail(tool::position pos);

protected:
	tool::position tailPos;
};

class Body {
public:
	Body(tool::sqrSize size, COLORREF color);

protected:
	tool::sqrSize bodySize;
	COLORREF bodyColor;
};

class Snake : public Body, public Head, public Tail {
public:
	Snake(tool::sqrSize size, tool::position pos, COLORREF color);

	std::list<tool::position> snakePosition{ headPos };

	const tool::position& getHeadPosition();
	const tool::position& getTailPosition();
	const tool::sqrSize& getBodySize();
	std::list<tool::position> getSnakePosition();
	COLORREF getBodyColor();

private:

};

#endif