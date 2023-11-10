#pragma once
#include "raylib.h"

struct Player
{
	Vector2 Pos;
	Vector2 InitPos;
	float Speed;
	float Height;
	float Width;
	bool Jump;
};