#include "Controller.h"

Information::Information(Snake snake, Game game, double speed)
{
    headPos = snake.getHeadPosition();
    mapSize = game.getSize();
    tailPos = snake.getTailPosition();
    bodySize = snake.getBodySize();
    bodyColor = snake.getBodyColor();
    mapColor = game.getColor();
    edgeLength = game.getEdgeLength();
    snakePosition = snake.getSnakePosition();
    this->speed = speed;
    direc = UP;
}

Controller::Controller(Snake snake, Game game, double speed) : Information(snake, game, speed)
{
	
}

void Controller::update()
{
    clock_t oldTime = clock();

    tool::position&& pos = spawnFoodPos();
    setfillcolor(YELLOW);
    solidcircle(pos.x, pos.y, bodySize.x > bodySize.y ? bodySize.y / 2 : bodySize.x / 2);

    while (true) {
        // 自动移动蛇
        if (clock() > oldTime + speed * 100) {
            oldTime = clock();
            moveSnake();
        }   
        // 获取键盘输入
        if (_kbhit()) {
            char ch = _getch();
            if (getKMsg == false) {
                switch (ch) {
                case 'a': if (direc != RIGHT || (int)snakePosition.size() == 1) direc = LEFT; getKMsg = true; break;
                case 'd': if (direc != LEFT || (int)snakePosition.size() == 1) direc = RIGHT; getKMsg = true; break;
                case 's': if (direc != UP || (int)snakePosition.size() == 1) direc = DOWN; getKMsg = true; break;
                case 'w': if (direc != DOWN || (int)snakePosition.size() == 1) direc = UP; getKMsg = true; break;
                }
            }
        }
        // 吃到食物

    }
}

void Controller::moveSnake()
{
    std::list<tool::position>::iterator iterHead = snakePosition.begin();
    std::list<tool::position>::iterator iterTail = snakePosition.end();
    iterTail--;

    switch (direc) {
        case RIGHT: moveHead((*iterHead).x + bodySize.x, (*iterHead).y); if (eatFood == false) deleTail((*iterTail).x, (*iterTail).y); eatFood = false; break;
        case LEFT: moveHead((*iterHead).x - bodySize.x, (*iterHead).y); if (eatFood == false) deleTail((*iterTail).x, (*iterTail).y); eatFood = false; break;
        case DOWN: moveHead((*iterHead).x, (*iterHead).y + bodySize.y); if (eatFood == false) deleTail((*iterTail).x, (*iterTail).y); eatFood = false; break;
        case UP: moveHead((*iterHead).x, (*iterHead).y - bodySize.y); if (eatFood == false) deleTail((*iterTail).x, (*iterTail).y); eatFood = false; break;
    }
}

void Controller::moveHead(int x, int y)
{
    detect(x, y);
    setfillcolor(bodyColor);
    solidrectangle(x - bodySize.x / 2, y - bodySize.y / 2, x + bodySize.x / 2, y + bodySize.y / 2);
    tool::position temp{ x, y };
    snakePosition.emplace_front(temp);
    getKMsg = false;
}

void Controller::deleTail(int x, int y)
{
    setfillcolor(RGB(GetRValue(mapColor) + 15, GetGValue(mapColor) + 15, GetBValue(mapColor) + 15));
    solidrectangle(x - bodySize.x / 2, y - bodySize.y / 2, x + bodySize.x / 2, y + bodySize.y / 2);
    snakePosition.pop_back();
}

void Controller::detect(int x, int y)
{
    COLORREF targetColor = getpixel(x, y);
    if (targetColor == mapColor || targetColor == bodyColor) {
        settextcolor(RED);
        settextstyle(36, 0, _T("Consolas"));
        setbkmode(TRANSPARENT);

        outtextxy(mapSize.x / 3, mapSize.y / 3, _T("Game Fail!"));
        outtextxy(mapSize.x / 20, mapSize.y / 3 + 36, _T("Type any key to leave!"));
        char ch = getchar();
        exit(0);
    }
    else if (targetColor == YELLOW) {
        eatFood = true;
        tool::position&& pos = spawnFoodPos();
        setfillcolor(YELLOW);
        solidcircle(pos.x, pos.y, bodySize.x > bodySize.y ? bodySize.y / 2 : bodySize.x / 2);
    }
}

tool::position Controller::spawnFoodPos()
{
    std::default_random_engine engine((unsigned int)time(0));
    std::uniform_int_distribution<unsigned int> randomX(0, (mapSize.x - edgeLength * 2) / bodySize.x - 1);
    std::uniform_int_distribution<unsigned int> randomY(0, (mapSize.y - edgeLength * 2) / bodySize.y - 1);

    int x = randomX(engine);
    int y = randomY(engine);

    x = x * bodySize.x + bodySize.x / 2 + edgeLength;
    y = y * bodySize.y + bodySize.y / 2 + edgeLength;

    tool::position temp{ x, y };
    
    return temp;
}