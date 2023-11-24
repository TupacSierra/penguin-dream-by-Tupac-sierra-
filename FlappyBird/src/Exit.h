#pragma once
#include "GameScreenEnum.h"
#include <raylib.h>
void DrawExit(Vector2& Mouse);
void ExitLogic(Vector2& Mouse, GameScreen& currentScreen);
bool CheckButtonHovered(Vector2 mouse, int x, int y, int width, int height);
bool CheckButtonClicked(Vector2 mouse, int x, int y, int width, int height);