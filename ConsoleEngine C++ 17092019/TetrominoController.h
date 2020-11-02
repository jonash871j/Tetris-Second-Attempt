#pragma once
#include "TetrisMap.h"
#include "Tetromino.h"
#include "Input.h"

class TetrominoController : private Tetromino
{
private:
	bool storedABrick = false;
	bool warpBrick = false;
	bool gameOver = false;
	int xPos, yPos;
	int hsp, vsp, rsp;
	int score = 0;
	byte lineCount = 0;
	byte currentIndex = 0, nextIndex = 0;
	sbyte holdIndex = -1;
	sbyte tRoate = 0, tcRoate = 0;

private:
	void ResetGame();
	void ResetPosition();
	void SelectRandomBrick();
	void SetStoredBrick();

public:
	TetrominoController();

	void SetInput(byte keyLeft, byte keyRight, byte keyDown, byte keyRotate, byte keyBrickSave, byte keyWarp);
	void SetLogic(TetrisMap tetris, int gameSpeed);

public:
	PROPERTY(bool, GameOver);
	GET(GameOver) { return gameOver; }
	SET(GameOver) { gameOver = value; }

	PROPERTY(int, Score);
	GET(Score) { return score; }
	SET(Score) { score = value; }

	READONLY_PROPERTY(int, NextIndex);
	GET(NextIndex) { return nextIndex; }

	READONLY_PROPERTY(int, HoldIndex);
	GET(HoldIndex) { return holdIndex; }

	READONLY_PROPERTY(int, CurrentIndex);
	GET(CurrentIndex) { return currentIndex; }
};

