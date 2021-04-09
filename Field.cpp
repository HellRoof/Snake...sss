#include "Field.h"


Field::Field()
{
    field.resize(width);
    for (auto& column : field)
    {
        column.resize(height);
        for (auto& row : column)
        {
            row = std::make_pair<char, int>(' ', 0);
        }
    }
}

void Field::set_sub(int x, int y, int parameter)
{
    if (x >= 0 && x <= (int)width - 1 && y >= 0 && y <= (int)height - 1)
    {
        field[x][y].second = parameter;
    }
}

void Field::set(int x, int y, char stateChar, int parameter)
{
    field[x][y].first = stateChar;
    field[x][y].second = parameter;
}

void Field::Make_Wall()
{
    //Set Top and Bottom Wall
    //for (size_t i = 0; i < width; i++)
    //{
    //    field[i][0].first = '#';
    //    field[i][height-1].first = '#';
    //}
    ////Set Left and Right Wall
    //for (size_t j = 0; j < height; ++j)
    //{
    //    field[0][j].first = '#';
    //    field[width-1][j].first = '#';
    //}

    //Set Top and Bottom Wall
    for (size_t i = 0; i < width; ++i)
    {
        set(i, 0, '#', WALL);
        set(i, height - 1, '#', WALL);
    }
    //Set Left and Right Wall
    for (size_t j = 0; j < height; ++j)
    {
        set(0, j, '#', WALL);
        set(width - 1, j, '#', WALL);
    }
}

void Field::Set_Fly(Fly& fly)
{
    set(fly.x, fly.y, 'F');
    /*field[fly.x][fly.y].first = 'F';*/
}

void Field::Print()
{
    for (size_t row{ 0 }; row < height; ++row)
    {
        for (size_t column{ 0 }; column < width; ++column)
        {
            std::cout << get(column, row).first;
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

char Field::GetFieldCoords(int x, int y)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
            if ((i == x) && (j == y))
            {
                char returnValue = field[x][y].first;
                return returnValue;
            }
            
		}
	}
}

void Field::SetFieldCoords(int set_x, int set_y, char value)
{
    field[set_x][set_y].first = value;
}

void Field::Clear()
{
    for (auto& column : field)
    {
        column.resize(height);
        for (auto& row : column)
        {
            row = std::make_pair<char, int>(' ', 0);
        }
    }
}

void Field::PrintFlyCoords(Fly& fly)
{
    std::cout << "X is: " << fly.x << "Y is: " << fly.y << std::endl;
}
