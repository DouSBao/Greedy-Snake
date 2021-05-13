#ifndef MAP_H
#define MAP_H

#include <graphics.h>
#include "Tool.h"

/* 
 * File: Map.h
 * ----------------
 * Time: 11 May 2021
 * Coder: DouSBao
 * Funtion: Init the game map
 */

class Map {
public:
	Map(tool::sqrSize pos, COLORREF color);

protected:
	// 窗口大小
	tool::sqrSize mapSize;
	// 窗口颜色
	COLORREF mapColor;
};

// 边缘碰撞体
class Edge {
public:
	Edge(int length);

protected:
	// 边缘碰撞体宽度
	int edgeLength;
};

// 总游戏界面
class Game : public Map, public Edge {
public:
	Game(tool::sqrSize pos, int length, COLORREF color);

	// 获取窗口大小
	const tool::sqrSize& getSize();
	// 获取窗口颜色
	COLORREF getColor();
	// 获取碰撞体宽度
	int getEdgeLength();

private:
	void initWindow();
};

#endif