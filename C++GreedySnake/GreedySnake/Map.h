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
	// ���ڴ�С
	tool::sqrSize mapSize;
	// ������ɫ
	COLORREF mapColor;
};

// ��Ե��ײ��
class Edge {
public:
	Edge(int length);

protected:
	// ��Ե��ײ����
	int edgeLength;
};

// ����Ϸ����
class Game : public Map, public Edge {
public:
	Game(tool::sqrSize pos, int length, COLORREF color);

	// ��ȡ���ڴ�С
	const tool::sqrSize& getSize();
	// ��ȡ������ɫ
	COLORREF getColor();
	// ��ȡ��ײ����
	int getEdgeLength();

private:
	void initWindow();
};

#endif