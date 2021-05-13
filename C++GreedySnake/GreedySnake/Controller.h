#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <graphics.h>
#include <ctime>
#include <conio.h>
#include <random>
#include "Tool.h"
#include "Map.h"
#include "Snake.h"

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

typedef int direction;

/* 
 * File: Controller.h
 *--------------------
 * Coder: DouSBao
 * Time: 12 May 2021
 * Function: Providing the function for user to move the snake
 */

static bool eatFood;
static bool getKMsg;

class Information {
public:
    Information(Snake snake, Game game, double speed);

protected:
    tool::position headPos;
    tool::position tailPos;
    tool::sqrSize bodySize;
    tool::sqrSize mapSize;
    std::list<tool::position> snakePosition;
    COLORREF bodyColor;
    COLORREF mapColor;
    int edgeLength;
    double speed;
    direction direc;
};

class Controller : public Information {
public:
    Controller(Snake snake, Game game, double speed);

    void update();

private:
    void moveSnake();
    void moveHead(int x, int y);
    void deleTail(int x, int y);
    void detect(int x, int y);
    tool::position spawnFoodPos();
};

#endif
