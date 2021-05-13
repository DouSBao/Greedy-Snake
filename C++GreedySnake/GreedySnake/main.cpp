#include <iostream>
#include "Controller.h"

tool::sqrSize snakeBodySize = { 10, 10 };
tool::sqrSize windowSize = { 400, 400 };
tool::position snakeInitPos = { 195, 195 };
COLORREF snakeColor = BLACK;
int edgeLength = 20;
double moveSpeed = 3;

int main(void)
{
	Game game(windowSize, edgeLength, RGB(128, 128, 128));
	Snake snake(snakeBodySize, snakeInitPos, snakeColor);
	Controller controller(snake, game, moveSpeed);
	controller.update();

	getchar();

	return 0;
}