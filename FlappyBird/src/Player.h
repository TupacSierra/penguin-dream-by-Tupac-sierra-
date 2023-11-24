#pragma once
#include "raylib.h"

struct Player
{
	Vector2 pos;
	Vector2 initPos;
	float speed;
	float heingt;
	float width;
	bool jump;
	float jumpSpeed;

};