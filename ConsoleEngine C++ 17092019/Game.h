#pragma once
#include "TetrominoController.h"
#include "Engine.h"

class Game
{
private:
	TetrisMap tetris;
	TetrominoController tetrisControl;
	Tetromino tetrominoNext;
	Tetromino tetrominoStored;
	Font fntTetris{ "./Font/fntTetris/", 3, 4 };
	ColorPalette cpTetris{"./Color/Tetris"};

private:
	void LogicMain();
	void DrawMain();
	void DrawGameOver();
	void DrawScorecounter();

public:
	Game();
	void PlayGame();
public:
	PROPERTY(ColorPalette, CpTetris);
	GET(CpTetris) { return cpTetris; }
};

