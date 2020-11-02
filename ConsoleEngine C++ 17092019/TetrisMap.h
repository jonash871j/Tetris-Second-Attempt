#pragma once
#include "Scene.h"

class TetrisMap
{
private:
	Sprite sprBorderVertical{ 1, 3, 3 };
	Sprite sprBorderHorizontal{ 1, 3, 3 };
	Sprite sprBorderTLeft{ 1, 3, 3 };
	Sprite sprBorderTRight{ 1, 3, 3 };
	Sprite sprBorderUpLeft{ 1, 3, 3 };
	Sprite sprBorderUpRight{ 1, 3, 3 };
	Sprite sprBorderLwLeft{ 1, 3, 3 };
	Sprite sprBorderLwRight{ 1, 3, 3 };

	Sprite sprLine { 1, 3, 3 }; 
	Sprite sprTetromino01 {1, 3, 3}; // Cyan
	Sprite sprTetromino02 {1, 3, 3}; // Blue
	Sprite sprTetromino03 {1, 3, 3}; // Orange
	Sprite sprTetromino04 {1, 3, 3}; // Yellow
	Sprite sprTetromino05 {1, 3, 3}; // Green
	Sprite sprTetromino06 {1, 3, 3}; // Violet
	Sprite sprTetromino07 {1, 3, 3}; // Red

private:
	Scene map{ 10, 21, 3, 3, 3, 3 };
	Scene next{ 4, 4, 3, 3, 3, 3 };
	Scene stored{ 4, 4, 3, 3, 3, 3 };
	Scene border{ 12, 23, 3, 3, 3, 3 };
	Scene borderDetail{ 22, 22, 3, 3, 3, 3 };

public:
	TetrisMap();
	void ImportResources();

public:
	PROPERTY(Scene, Map);
	GET(Map) { return map; }
	SET(Map) { map = value; }

	PROPERTY(Scene, Next);
	GET(Next) { return next; }
	SET(Next) { next = value; }

	PROPERTY(Scene, Stored);
	GET(Stored) { return stored; }
	SET(Stored) { stored = value; }

	READONLY_PROPERTY(Scene, Border);
	GET(Border) { return border; }

	READONLY_PROPERTY(Scene, BorderDetail);
	GET(BorderDetail) { return borderDetail; }
};

