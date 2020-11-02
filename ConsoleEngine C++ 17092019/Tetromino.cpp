#include "Tetromino.h"

void Tetromino::RotateShape(int i, int x, int y)
{
	if (tetrominoMap[shapeIndex][y][x] != ' ')
		tetromino[0][i] = tetrominoMap[shapeIndex][y][x];
	else
		tetromino[0][i] = ' ';
}

void Tetromino::RotateShapeCheck(int i, int x, int y)
{
	if (tetrominoMap[shapeIndex][y][x] != ' ')
		tetrominoCheck[0][i] = tetrominoMap[shapeIndex][y][x];
	else
		tetrominoCheck[0][i] = ' ';

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (tetrominoCheck[y][x] != ' ')
				tetrominoCheck[y][x] = '1';
}

Tetromino::Tetromino() {}

void Tetromino::ClearShape(Scene scene)
{
	for (int y = 0; y < scene.GetHeight(); y++)
		for (int x = 0; x < scene.GetHeight(); x++)
			for (char i = 'a'; i <= 'g'; i++)
				if (scene.GetArray(x, y) == i)
					scene.SetTile(x, y, ' ');
}

void Tetromino::SetShape(byte shapeIndex, byte direction)
{
	if (shapeIndex < 0) shapeIndex = 0;
	if (shapeIndex > 6) shapeIndex = 6;
	this->shapeIndex = shapeIndex;
	this->direction = direction;

	switch (direction)
	{
	case 0: 
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShape(y * 4 + x, x, y);
		return;
	case 1: 
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShape(12 + y - (x * 4), x, y);
		return;
	case 2: 
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShape(15 - (y * 4) - x, x, y);
		return;
	case 3: 
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShape(3 - y + (x * 4), x, y);
		return;
	}
}

void Tetromino::CheckShape(byte shapeIndex, byte direction)
{
	if (shapeIndex < 0) shapeIndex = 0;
	if (shapeIndex > 6) shapeIndex = 6;
	this->shapeIndex = shapeIndex;
	this->direction = direction;

	switch (direction)
	{
	case 0:
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShapeCheck(y * 4 + x, x, y);
		return;
	case 1:
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShapeCheck(12 + y - (x * 4), x, y);
		return;
	case 2:
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShapeCheck(15 - (y * 4) - x, x, y);
		return;
	case 3:
		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				RotateShapeCheck(3 - y + (x * 4), x, y);
		return;
	}
}

void Tetromino::SetShapeStatic()
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (tetromino[y][x] != ' ')
				tetromino[y][x] = tetromino[y][x] - char(48);
}

void Tetromino::SetToMap(Scene scene, int xPos, int yPos)
{
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			if (tetromino[y][x] != ' ')
				scene.SetTile(x + xPos, y + yPos, tetromino[y][x]);
}