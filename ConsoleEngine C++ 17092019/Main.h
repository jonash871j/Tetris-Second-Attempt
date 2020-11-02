#pragma once

class Main
{
public:
	void Start();
	void Update();
};

#pragma region
#define start Main::Start
#define update Main::Update
int main() 
{ 
	Main game; 
	game.Start(); 
	while (1) 
		game.Update(); 
	return 0; 
}

#pragma endregion