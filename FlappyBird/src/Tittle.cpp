#pragma once
#include "Tittle.h"

void DrawTittle(const int& width, const int& height, Vector2& Mouse)
{
	DrawText("Penguin Dream", static_cast<int> (width) / 3, static_cast<int> (height) / 4, 60, GOLD);
	DrawText("Use the Mouse and Left Click", static_cast<int>(GetScreenWidth()) / 2 - 20, static_cast<int>(GetScreenHeight()) / 2 + 245, 15, GRAY);
	if (Mouse.y >= (GetScreenHeight() / 2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 30) && Mouse.x >= ((GetScreenWidth() / 2) - 40) && Mouse.x <= ((GetScreenWidth() / 2) + 60))
	{
		DrawText("Play", static_cast<int>(GetScreenWidth()) / 2, GetScreenHeight() / 2 - 50, 30, GRAY);
	}
	else
	{
		DrawText("Play", static_cast<int>(GetScreenWidth()) / 2, GetScreenHeight() / 2 - 50, 30, GOLD);
	}

	if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 100))
	{
		DrawText("Credits", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2 - 20, 30, GRAY);
	}
	else
	{
		DrawText("Credits", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2 - 20, 30, GOLD);
	}
	if (Mouse.y >= (GetScreenHeight() / 1.5 - 20) && Mouse.y <= (GetScreenHeight() / 1.5 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 50))
	{
		DrawText("Exit", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2 + 10, 30, GRAY);
	}
	else
	{
		DrawText("Exit", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2 + 10, 30, GOLD);
	}
}

void TittleLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	if (Mouse.y >= (GetScreenHeight() / 2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 60))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::TUTORIAL;

		}
	}
	if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 100))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::CREDIT;
		}
	}
	if (Mouse.y >= (GetScreenHeight() / 1.5 - 20) && Mouse.y <= (GetScreenHeight() / 1.5 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 50))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::ASKEXIT;
		}
	}
}