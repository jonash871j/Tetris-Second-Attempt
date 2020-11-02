#include "Game.h"
#include "Main.h"	

Game game;

void TetrisSplashScreen(int duration)
{
	Sprite splash(1, 48, 10);
	splash.ImportLayer("./Sprite/spr_tetrisLogo", 0);
	for (int i = 0; i < duration; i++) {
		Draw::Background(cFULL, BLACK);
		Draw::SpritePlain(splash, XMID - 21, YMID - 16);
		Console::WriteString(0, SCREENHEIGHT - 1, "v1.0 beta", 0, WHITE);
		Console::WriteString(SCREENWIDTH - 4, SCREENHEIGHT - 1, "2019", 0, WHITE);
		Console::Delay(1);
		Console::Update();
		if (Input::KeyPressed(VK_RETURN))
			return;
	}
}

void start()
{	
	Console::Create(66, 67);
	Console::SetFont(L"Terminal", 8, 8);
	Console::SetWindowTitle("TETRIS");

	Console::SetColorPalette(cpDefault);
	Draw::SplashScreen(500);
	cpDefault.FadeOut(1, 4);
	Console::Delay(100);
	Console::SetColorPalette(game.CpTetris);
	game.CpTetris.FadeOut(0, 255);
	TetrisSplashScreen(1);
	game.CpTetris.FadeIn(1, 4);
	TetrisSplashScreen(500);
	game.CpTetris.FadeOut(1, 4);
	Draw::Background(cFULL, BLACK);
	Console::Update();
	Console::SetColorPalette(game.CpTetris);
}

void update()
{
	if (Console::GetFullscreen() == true)
		Console::SetFont(L"Terminal", 16, 16);
	else
		Console::SetFont(L"Terminal", 8, 8);

	// Drawing
	game.PlayGame();
	Console::Update();

}