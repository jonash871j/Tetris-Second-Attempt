#include "TetrominoController.h"
#include <thread>
#include <ctime>
#include "Sound.h"

bool moveBrick = false;
int speed = 800;

void SetTiming()
{
	while (1)
	{
		moveBrick = true;
		Console::Delay(speed);
	}
}std::thread timing(SetTiming);

void TetrominoController::ResetGame()
{
	Sound::Play("./Sound/lose.wav");
	lineCount = 0;
	holdIndex = -1;
	gameOver = true;

	SelectRandomBrick();
	ResetPosition();
}

void TetrominoController::ResetPosition()
{
	storedABrick = false;
	hsp = 0, vsp = 0, rsp = 0;
	xPos = 3, yPos = -4;
}

void TetrominoController::SelectRandomBrick()
{
	currentIndex = nextIndex;
	nextIndex = Random(0, 7);
}

void TetrominoController::SetStoredBrick()
{
	if (storedABrick == false)
	{
		Sound::Play("./Sound/tohold.wav");
		if (holdIndex == -1)
		{
			holdIndex = currentIndex;
			SelectRandomBrick();
			ResetPosition();
			storedABrick = true;
		}
		else
		{
			int a = holdIndex;
			holdIndex = currentIndex;
			currentIndex = a;
			ResetPosition();
			storedABrick = true;
		}
	}
}

TetrominoController::TetrominoController() 
{
	srand(time(NULL));
	nextIndex = Random(0, 7);
	SelectRandomBrick();
	ResetPosition();
}

void TetrominoController::SetInput(byte keyLeft, byte keyRight, byte keyDown, byte keyRotate, byte keyBrickSave, byte keyWarp)
{
	hsp = Input::KeyStateDelayedLoop(keyRight) - Input::KeyStateDelayedLoop(keyLeft);
	vsp = Sign(Input::KeyStateDelayed(keyDown, 10) + moveBrick);
	rsp = Input::KeyPressed(keyRotate);
	warpBrick = Input::KeyPressed(keyWarp);
	if (Input::KeyPressed(keyBrickSave))
		SetStoredBrick();

	// Roate logic
	if (tRoate < 0) tRoate = 3;
	
	tcRoate = tRoate;
	tcRoate -= rsp;
	if (tcRoate < 0) tcRoate = 3;
	moveBrick = false;
}

void TetrominoController::SetLogic(TetrisMap tetris, int gameSpeed)
{
	do
	{
		speed = gameSpeed;
		CheckShape(currentIndex, tcRoate);

		if (warpBrick == true) {
			score += 1;
			vsp = 1;
		}

		// Collision handling ********************************************************************
		// Collision handling for rotating and x axis
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				// Rotation collision ************************************************************
				if (GetArray(x, y) != ' ')
				{
					for (char i = 0; i < 8; i++) {
						// Collision with a brick in map
						if (tetris.Map.GetArray(x + xPos, y + yPos) == GetArray(x, y) + i)
							rsp = 0;

						// Collision with border
						if (tetris.Border.GetArray(x + xPos + 1, y + yPos + 1) == GetArray(x, y) - 14)
							rsp = 0;
					}
				}

				// x axis
				if (tetromino[y][x] != ' ')
				{
					// Border collision **********************************************************
					if ((x + xPos + hsp + 1 <= 0) || (x + xPos + hsp + 1 > 10))
						hsp = 0;

					// Tetromino collision *******************************************************
					for (char i = '1'; i < '8'; i++)
					{
						if (tetris.Map.GetArray(x + xPos + hsp, y + yPos) == i)
							hsp = 0;
					}
				}
			}
		}xPos += hsp; tRoate -= rsp;

		// Collision handling for y axis
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				if (tetromino[y][x] != ' ')
				{
					// y axis
					if (y + yPos + vsp + 1 > 21)
					{
						Sound::Play("./Sound/harddrop.wav");
						SetShapeStatic();
						SetToMap(tetris.Map, xPos, yPos);
						SelectRandomBrick();
						ResetPosition();
						vsp = 0;
						score += 1;
						warpBrick = false;
					}

					// y axis
					for (char i = '1'; i < '8'; i++)
					{
						if (tetris.Map.GetArray(x + xPos, y + yPos + vsp) == i)
						{
							Sound::Play("./Sound/harddrop.wav");
							SetShapeStatic();
							SetToMap(tetris.Map, xPos, yPos);
							SelectRandomBrick();
							ResetPosition();
							vsp = 0;
							score += 1;
							warpBrick = false;
						}
					}
				}
			}
		}yPos += vsp;

		// Some sound code ***********************************************************************
		if (rsp == 1)
			Sound::Play("./Sound/rotate.wav");

		// Sound line point
		switch (lineCount)
		{
		case 1: Sound::Play("./Sound/1line.wav"); break;
		case 2: Sound::Play("./Sound/2line.wav"); break;
		case 3: Sound::Play("./Sound/3line.wav"); break;
		case 4: Sound::Play("./Sound/4line.wav"); break;
		}

		// Removeal of lines handling ************************************************************
		// Removes selected lines
		while (lineCount > 0)
		{
			score += 100 * lineCount;
			lineCount--;
			Console::Delay(100);

			for (int y = 0; y < 21; y++)
				for (int x = 0; x < 10; x++)
					if (tetris.Map.GetArray(x, y) == '*')
						for (int yDown = 21; yDown > 0; yDown--)
							if (y > yDown - 1)
								for (int x = 0; x < 10; x++)
									tetris.Map.SetTile(x, yDown, tetris.Map.GetArray(x, yDown - 1));
		}
		// Check for full lines
		for (int y = 0; y < 21; y++) {
			int count = 0;
			for (int x = 0; x < 10; x++) {
				for (char i = '1'; i < '8'; i++)
					if (tetris.Map.GetArray(x, y) == i)
						count++;

				if (count >= 10) {
					for (int i = 0; i < 10; i++)
						tetris.Map.SetTile(i, y, '*');
					lineCount++;
				}
			}
		}

		// Lose handling *************************************************************************
		// Check for lose
		for (int x = 0; x < 10; x++) {
			for (char i = '1'; i < '8'; i++) {
				if (tetris.Map.GetArray(x, 0) == i) {
					// Reset game
					for (int y = 0; y < 21; y++)
						for (int x = 0; x < 10; x++)
							tetris.Map.SetTile(x, y, ' ');
					ResetGame();
				}
			}
		}

		// General *******************************************************************************
		ClearShape(tetris.Map);
		SetShape(currentIndex, tRoate);
		SetToMap(tetris.Map, xPos, yPos);
	}while (warpBrick == true);
}