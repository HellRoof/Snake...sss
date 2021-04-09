#pragma once

enum class Direction
{
	STOP, RIGHT, LEFT, UP, DOWN, MAX_VALUE
};

enum MainMenuOption
{
	START_AS_PLAYER = 1, START_AS_BOT, EXIT
};

enum FieldState
{
	EMPTY = 0,
	WALL,
	FLY,
	SNAKE_HEAD,
	SNAKE_BODY,
	MAX_VALUE
};