#pragma once
#include "GameScreenEnum.h"
#include <raylib.h>
void DrawTutotial(Vector2& Mouse);
void TutotialLogic(Vector2& Mouse, GameScreen& currentScreen);
bool CheckButtonHovered(Vector2 mouse, int x, int y, int width, int height);
bool CheckButtonClicked(Vector2 mouse, int x, int y, int width, int height);