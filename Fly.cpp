#include "Fly.h"

void Fly::generate_Fly(Field& field)
{
    srand(time(NULL));
	
    while (true)
    {
        x = std::rand() % field.width;
        y = std::rand() % field.height;

        if ((field.GetFieldCoords(x, y) != '#') && (field.GetFieldCoords(x, y) != '@') && (field.GetFieldCoords(x, y) != '*'))
        {
            break;
        }
    }
}