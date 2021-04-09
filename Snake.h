#pragma once
#include <vector>
#include "Field.h"
#include "Constants_Enum.h"
//#include "Game.h"


class Field;

class Snake
{
private:
	
	struct SnakeNode
	{
		int x;
		int y;
	};

	struct Vector2D
	{
		int x{ 0 };
		int y{ 0 };
	};
	
protected:

public:
	std::vector<SnakeNode> snake_Array;

	//Snake Speed
	float snakeSpeed{0.5f};

	//Move flag
	bool try_ToMove{ true };
	std::vector<Vector2D> vect{ 1 };
	
	Snake();

	Direction direction{ Direction::UP };
	Direction actual_direction{ Direction::RIGHT };

	void direction_update()
	{
		actual_direction = direction;
	}

	void Restart();

	//Calculate snake direction
	Direction calculate_dir(std::vector<Vector2D> vec);
	
	void AI_move(Field& field);

	//Init snake on field
	void init_Snake();
	
	bool move(Field& field, Fly& fly);
	
	void handle_Player_Input();
	
	void copy_To_Field(Field& field);
};
