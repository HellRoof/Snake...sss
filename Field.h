#pragma once

#include <iostream>
#include <vector>
#include "Fly.h"
#include "Constants_Enum.h"

class Fly;

class Field
{
private:
	
protected:

public:

	Field();
	size_t const height{ 10 };
	size_t const width{ 10 };
	
		/*std::vector<std::vector<char>> field;*/
		std::vector<std::vector<std::pair<char, int>>> field;
	
	//void FieldInit();
	void Make_Wall();
	void Set_Fly(Fly& fly);
	void set_sub(int x, int y, int parameter);
	void set(int x, int y, char stateChar, int parameter = 0);
	void Print();
	char GetFieldCoords(int get_x, int get_y);
	void SetFieldCoords(int set_x, int set_y, char value);
	void Clear();
	void PrintFlyCoords(Fly& fly);
	
	std::pair<char, int> get(int heigth, int width)
	{
		return field[heigth][width];
	}
};