#pragma once
#include "Field.h"
#include "Snake.h"
#include "Fly.h"

//class Field;
//class Snake;

class Game
{
private:

protected:

public:
	Game();

	Field field;
	Snake snake;
	Snake snake_AI;
	Fly fly;

	//Game flag
	bool gameStart{ true };

	void StartGame();
	void GameOver();
};
