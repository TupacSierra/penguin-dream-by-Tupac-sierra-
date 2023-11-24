#pragma once

#pragma once

#include "raylib.h"
#include "GameScreenEnum.h"

void DrawTittle(Vector2& Mouse); 
void TittleLogic(Vector2& Mouse, GameScreen& currentScreen);
bool CheckButtonHovered(Vector2 mouse, int x, int y, int width, int height);
bool CheckButtonClicked(Vector2 mouse, int x, int y, int width, int height);