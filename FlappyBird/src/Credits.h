#pragma once
#include "GameScreenEnum.h"
#include <raylib.h>

void DrawCredit(Vector2& Mouse);
void CreditLogic(Vector2& Mouse, GameScreen& currentScreen);
void DrawTittle(Vector2& Mouse);
void TittleLogic(Vector2& Mouse, GameScreen& currentScreen);
bool CheckButtonHovered(Vector2 mouse, int x, int y, int width, int height);
bool CheckButtonClicked(Vector2 mouse, int x, int y, int width, int height);