#include "Game.h"

void Game::LogicMain()
{
	tetrisControl.SetInput(VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_RETURN, VK_SPACE);
	tetrisControl.SetLogic(tetris, 500);

	tetrominoStored.ClearShape(tetris.Stored);
	tetrominoStored.SetShape(tetrisControl.HoldIndex, 3);
	tetrominoStored.SetToMap(tetris.Stored, 0, 0);

	tetrominoNext.ClearShape(tetris.Next);
	tetrominoNext.SetShape(tetrisControl.NextIndex, 3);
	tetrominoNext.SetToMap(tetris.Next, 0, 0);
}

void Game::DrawMain()
{
	Draw::ScenePlain(tetris.Map, 18, -3);
	if (tetrisControl.HoldIndex >= 0)
		Draw::ScenePlain(tetris.Stored, 3, 3);
	Draw::ScenePlain(tetris.Next, 51, 3);
}

void Game::DrawGameOver()
{
	cpTetris.FadeOut(1, 8);
	Draw::Background(0, 0);
	Draw::ScenePlain(tetris.BorderDetail, 0, -3);
	Draw::Text(fntNormal, 18, 24, "GAMEOVER", tLEFTRIGHT, D_RED);
	Draw::Text(fntTetris, 0, 18, "Hold", tLEFTRIGHT, WHITE);
	Draw::Text(fntTetris, 51, 18, "Next", tLEFTRIGHT, WHITE);
	DrawScorecounter();
	cpTetris.FadeIn(1, 8);
}

void Game::DrawScorecounter()
{
	int scoreArray[8] = { 0 };
	scoreArray[7] = tetrisControl.Score % 10;
	scoreArray[6] = tetrisControl.Score / 10 % 10;
	scoreArray[5] = tetrisControl.Score / 100 % 10;
	scoreArray[4] = tetrisControl.Score / 1000 % 10;
	scoreArray[3] = tetrisControl.Score / 10000 % 10;
	scoreArray[2] = tetrisControl.Score / 100000 % 10;
	scoreArray[1] = tetrisControl.Score / 1000000 % 10;
	scoreArray[0] = tetrisControl.Score / 10000000 % 10;

	for (int i = 0; i < 8; i++)
		Draw::Text(fntTetris, (i * 4) + 17, 63, scoreArray[i], tLEFTRIGHT, WHITE);

}

Game::Game()
{
	tetris.ImportResources();
}

void Game::PlayGame()
{
	Draw::Rectangle(2, 2, 16, 16, 219, BLACK, false);
	Draw::Rectangle(50, 2, 64, 16, 219, BLACK, false);
	Draw::Rectangle(17, 0, 48, 60, 219, BLACK, false);
	Draw::ScenePlain(tetris.BorderDetail, 0, -3);

	if (tetrisControl.GameOver == false)
	{
		LogicMain();
		DrawMain();
		if (tetrisControl.GameOver == true)
			DrawGameOver();
	}
	else
	{
		Draw::Text(fntNormal, 18, 24, "GAMEOVER", tLEFTRIGHT, D_RED);
		if (Input::KeyReleased(VK_RETURN)) 
		{
			tetrisControl.GameOver = false;
			tetrisControl.Score = 0;
		}
	}

	Draw::Text(fntTetris, 0, 18, "Hold", tLEFTRIGHT, WHITE);
	Draw::Text(fntTetris, 51, 18, "Next", tLEFTRIGHT, WHITE);
	DrawScorecounter();

	Console::Delay(10);
}
