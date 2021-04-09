#include "Snake.h"
#include <cassert>
#include <conio.h>
#include "Game.h"


Snake::Snake()
{
	snake_Array.reserve( 100 );
	snake_Array.resize(3);
}

Direction Snake::calculate_dir(std::vector<Vector2D> vec)
{
	if (vec[0].x > 0 && vec[0].y == 0) { return Direction::RIGHT; }
	if (vec[0].x < 0 && vec[0].y == 0) { return Direction::LEFT; }
	if (vec[0].y > 0 && vec[0].x == 0) { return Direction::UP; }
	if (vec[0].y < 0 && vec[0].x == 0) { return Direction::DOWN; }
	assert(1 == 0);
	return Direction::UP;
}

void Snake::AI_move(Field& field)
{
	const int shift[4][2]{ {-1,0},{1,0},{0,-1},{0,1} };
	std::vector<SnakeNode> memory1;
	std::vector<SnakeNode> memory2;
	std::vector<SnakeNode>* pMem1{ &memory1 };
	std::vector<SnakeNode>* pMem2{ &memory2 };
	//starting wave
	int counter{ -1 };
	int x0{ snake_Array[0].x };
	int y0{ snake_Array[0].y };
	bool found{ false };
	memory1.clear();
	memory2.clear();
	memory1.push_back(SnakeNode{ x0,y0 });

	found = false;
	while (true)
	{
		pMem2->clear();
		for (auto& current_Node : (*pMem1))
		{
			for (int i{ 0 }; i < 4; ++i)
			{
				int x{ current_Node.x + shift[i][0] };
				int y{ current_Node.y + shift[i][1] };

				if (field.get(x, y).first == 'F')
				{

					field.set_sub(x, y, counter);
					x0 = x;
					y0 = y;
					found = true;
					break;
				}

				if (field.get(x, y).first == ' ' && field.get(x, y).second == EMPTY)
				{
					field.set_sub(x, y, counter);
					pMem2->push_back(SnakeNode{ x,y });
				}

			}
			if (found) { break; }

		}
		if (found) {
			break;
		}
		--counter;
		std::swap(pMem1, pMem2);
		}



		//moving backwards
		while (counter < -1)
		{
			for (int i{ 0 }; i < 4; ++i)
			{
				int x{ x0 + shift[i][0] };
				int y{ y0 + shift[i][1] };
				if ((field.get(x, y)).second == (counter + 1))
				{
					x0 = x;
					y0 = y;

					++counter; break;
				}

			}
		}

		//(x0,y0) is our next position

		vect[0].x = x0 - snake_Array[0].x;
		vect[0].y = snake_Array[0].y - y0;
		direction = calculate_dir(vect);
}

void Snake::init_Snake()
{
	snake_Array[0] = SnakeNode{ 4, 4 };
	snake_Array[1] = SnakeNode{ 4, 5 };
	snake_Array[2] = SnakeNode{ 4, 6 };
}

bool Snake::move(Field& field, Fly& fly)
{
	//getting new coordinates according to direction
	int snake_X{ snake_Array[0].x };
	int snake_Y{ snake_Array[0].y };
	switch (direction)
	{
	case (Direction::UP):
		snake_Y -= 1; break;
	case (Direction::DOWN):
		snake_Y += 1; break;
	case (Direction::LEFT):
		snake_X -= 1; break;
	case (Direction::RIGHT):
		snake_X += 1; break;
	}

	//checking new cell state
	char current_Cell{ field.get(snake_X, snake_Y).first };
	if (current_Cell == ' ' || current_Cell == 'F')
	{
		SnakeNode snake_Node{ snake_X, snake_Y };
		
		//move granted
		if (current_Cell == ' ')
		{
			snake_Array.pop_back();
			try_ToMove = true;
			snake_Array.insert(snake_Array.begin(), snake_Node);
		}
		else if (current_Cell == 'F')
		{
			fly.generate_Fly(field);
			snake_Array.insert(snake_Array.begin(), snake_Node);
		}
		
		direction_update();
		
		return true;
	}
	else if(current_Cell == '*' || current_Cell == '#')
	{
		//move denied
		std::cout << "Game Over" << std::endl;
		try_ToMove = false;
		return false;
	}
}


void Snake::Restart()
{
	snake_Array.reserve(100);
	snake_Array.resize(3);
	direction = Direction::UP;
}

void Snake::handle_Player_Input()
{
	if (_kbhit())
	{
		char getch;
		getch = _getch();

		if ((getch == 'w') && (actual_direction != Direction::DOWN))
		{
			direction = Direction::UP;
		}

		if ((getch == 's') && (actual_direction != Direction::UP))
		{
			direction = Direction::DOWN;
		}

		if ((getch == 'a') && (actual_direction != Direction::RIGHT))
		{
			direction = Direction::LEFT;
		}

		if ((getch == 'd') && (actual_direction != Direction::LEFT))
		{
			direction = Direction::RIGHT;
		}
	}
}

void Snake::copy_To_Field(Field& field)
{
	field.set(snake_Array[0].x, snake_Array[0].y, '@', SNAKE_HEAD);
	
	for (size_t index{ 1 }; index < snake_Array.size(); ++index)
	{
		field.set(snake_Array[index].x, snake_Array[index].y, '*', SNAKE_BODY);
	}
}
