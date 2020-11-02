#pragma once
#include "Scene.h"

class Tetromino
{
protected:
	char tetromino[4][4];
	char tetrominoCheck[4][4];
	char tetrominoMap[7][4][4] =
	{ 
		' ',' ',' ',' ',
		'a','a','a','a',
		' ',' ',' ',' ',
		' ',' ',' ',' ',
	
		' ',' ',' ',' ',
		'b','b','b',' ',
		' ',' ','b',' ',
		' ',' ',' ',' ',

		' ',' ','c',' ',
		'c','c','c',' ',
		' ',' ',' ',' ',
		' ',' ',' ',' ',

		' ',' ',' ',' ',
		' ','d','d',' ',
		' ','d','d',' ',
		' ',' ',' ',' ',

		' ',' ',' ',' ',
		' ','e','e',' ',
		'e','e',' ',' ',
		' ',' ',' ',' ',

		' ',' ',' ',' ',
		'f','f','f',' ',
		' ','f',' ',' ',
		' ',' ',' ',' ',

		' ',' ',' ',' ',
		'g','g',' ',' ',
		' ','g','g',' ',
		' ',' ',' ',' ',
	};

protected:
	byte shapeIndex = 0;
	byte direction = 0;

private:
	void RotateShape(int i, int x, int y);
	void RotateShapeCheck(int i, int x, int y);

public:
	Tetromino();
	
	void ClearShape(Scene scene);
	void SetShape(byte shapeIndex, byte direction);
	void CheckShape(byte shapeIndex, byte direction);
	void SetShapeStatic();
	void SetToMap(Scene scene, int xPos, int yPos);

protected:
	inline char GetArray readonly_2D tetrominoCheck[y][x] rs
};

