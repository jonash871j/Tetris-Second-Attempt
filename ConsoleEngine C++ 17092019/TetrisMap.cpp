#include "TetrisMap.h"

TetrisMap::TetrisMap() 
{
	for (int y = 0; y < map.GetHeight(); y++) {
		for (int x = 0; x < map.GetWidth(); x++) {
			map.SetTile(x, y, ' ');
			next.SetTile(x, y, ' ');
		}
	}
	border.ImportMap("border");
	borderDetail.ImportMap("borderDetail");
};

void TetrisMap::ImportResources()
{
	sprBorderVertical.ImportLayer("./Sprite/spr_tBorderVertical", 0);
	sprBorderHorizontal.ImportLayer("./Sprite/spr_tBorderHorizontal", 0);
	sprBorderTLeft.ImportLayer("./Sprite/spr_tBorderTLeft", 0);
	sprBorderTRight.ImportLayer("./Sprite/spr_tBorderTRight", 0);
	sprBorderUpLeft.ImportLayer("./Sprite/spr_tBorderUPLeft", 0);
	sprBorderUpRight.ImportLayer("./Sprite/spr_tBorderUPRight", 0);
	sprBorderLwLeft.ImportLayer("./Sprite/spr_tBorderLWLeft", 0);
	sprBorderLwRight.ImportLayer("./Sprite/spr_tBorderLWRight", 0);
	sprLine.ImportLayer("./Sprite/spr_tLine", 0);
	sprTetromino01.ImportLayer("./Sprite/spr_tTetromino01", 0);
	sprTetromino02.ImportLayer("./Sprite/spr_tTetromino02", 0);
	sprTetromino03.ImportLayer("./Sprite/spr_tTetromino03", 0);
	sprTetromino04.ImportLayer("./Sprite/spr_tTetromino04", 0);
	sprTetromino05.ImportLayer("./Sprite/spr_tTetromino05", 0);
	sprTetromino06.ImportLayer("./Sprite/spr_tTetromino06", 0);
	sprTetromino07.ImportLayer("./Sprite/spr_tTetromino07", 0);

	borderDetail.SetSpriteID(unsigned char(179), sprBorderVertical);
	borderDetail.SetSpriteID(unsigned char(196), sprBorderHorizontal);
	borderDetail.SetSpriteID(unsigned char(180), sprBorderTLeft);
	borderDetail.SetSpriteID(unsigned char(195), sprBorderTRight);
	borderDetail.SetSpriteID(unsigned char(218), sprBorderUpLeft);
	borderDetail.SetSpriteID(unsigned char(191), sprBorderUpRight);
	borderDetail.SetSpriteID(unsigned char(192), sprBorderLwLeft);
	borderDetail.SetSpriteID(unsigned char(217), sprBorderLwRight);
	map.SetSpriteID('*', sprLine);
	map.SetSpriteID('1', sprTetromino01);
	map.SetSpriteID('a', sprTetromino01); next.SetSpriteID('a', sprTetromino01); stored.SetSpriteID('a', sprTetromino01);
	map.SetSpriteID('2', sprTetromino02);
	map.SetSpriteID('b', sprTetromino02); next.SetSpriteID('b', sprTetromino02); stored.SetSpriteID('b', sprTetromino02);
	map.SetSpriteID('3', sprTetromino03);
	map.SetSpriteID('c', sprTetromino03); next.SetSpriteID('c', sprTetromino03); stored.SetSpriteID('c', sprTetromino03);
	map.SetSpriteID('4', sprTetromino04);
	map.SetSpriteID('d', sprTetromino04); next.SetSpriteID('d', sprTetromino04); stored.SetSpriteID('d', sprTetromino04);
	map.SetSpriteID('5', sprTetromino05);
	map.SetSpriteID('e', sprTetromino05); next.SetSpriteID('e', sprTetromino05); stored.SetSpriteID('e', sprTetromino05);
	map.SetSpriteID('6', sprTetromino06);
	map.SetSpriteID('f', sprTetromino06); next.SetSpriteID('f', sprTetromino06); stored.SetSpriteID('f', sprTetromino06);
	map.SetSpriteID('7', sprTetromino07);
	map.SetSpriteID('g', sprTetromino07); next.SetSpriteID('g', sprTetromino07); stored.SetSpriteID('g', sprTetromino07);
}