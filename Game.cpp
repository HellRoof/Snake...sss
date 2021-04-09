#include "Game.h"
# include <windows.h>
#include "Menu.h"

Game::Game()
{
	field.Make_Wall();
	fly.generate_Fly(field);
	field.Set_Fly(fly);
	snake.copy_To_Field(field);
}

//Main game cycle
void Game::StartGame()
{
	bool gameProcess{ true };
	while (gameProcess)
	{

		Menu mainMenu("MAIN MENU");
		mainMenu.addOption("Start Tournament      ");
		mainMenu.addOption("Computer Player");
		mainMenu.addOption("Exit");

		MainMenuOption option{ static_cast<MainMenuOption>(mainMenu.askOption()) };
		switch (option)
		{
		case(START_AS_PLAYER):
		{
			snake.init_Snake();
			snake.copy_To_Field(field);
				
			while (gameStart)
			{
				snake.handle_Player_Input();
				snake.move(field, fly);
				snake.copy_To_Field(field);
				field.Print();
				field.Clear();
				field.Make_Wall();
				field.Set_Fly(fly);
				field.PrintFlyCoords(fly);
				snake.copy_To_Field(field);
				gameStart = snake.try_ToMove;
				
				Sleep((1 * 1000) / (snake.snake_Array.size() * snake.snakeSpeed) );
				std::system("CLS");
			}
			GameOver();
			snake.Restart();
			break;
		}
		case(START_AS_BOT):
		{
			snake_AI.init_Snake();
			snake_AI.copy_To_Field(field);
				while (gameStart)
				{
					field.Set_Fly(fly);
					snake_AI.AI_move(field);
					snake_AI.copy_To_Field(field);
					snake_AI.move(field, fly);
					
					field.Print();
					field.Clear();
					field.Make_Wall();
					snake_AI.copy_To_Field(field);
					field.Set_Fly(fly);
					field.PrintFlyCoords(fly);
					gameStart = snake_AI.try_ToMove;
					
					Sleep((1 * 3000) / snake_AI.snake_Array.size());
					std::system("CLS");
				}
				GameOver();
				snake_AI.Restart();
				break;
		}
		case(EXIT):
		{
			gameProcess = false;
			break;
		}
		}
	}
}

void Game::GameOver()
{
	std::cout << "GAME OVER" << std::endl;
	Sleep((1 * 1000));
	std::system("CLS");
	field.Clear();
	field.Make_Wall();
	field.Set_Fly(fly);
	gameStart = true;
}
