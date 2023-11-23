#include "Exit.h"
#include "GameLoop.h"

void DrawExit(Vector2& Mouse)
{
	DrawText("You sure you want to close the game ?", static_cast<int>(GetScreenWidth()) / 8, GetScreenHeight() / 2, 40, GOLD);
	if (Mouse.y >= ((GetScreenHeight() / 1.5) - 10) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		DrawText("Yes", static_cast<int>(GetScreenWidth()) / 3, static_cast<int>(GetScreenHeight()) / 2, 30, GRAY);
	}
	else
	{
		DrawText("Yes", static_cast<int>(GetScreenWidth()) / 3, static_cast<int>(GetScreenHeight()) / 2, 30, GOLD);
	}

	if (Mouse.y >= ((GetScreenHeight() / 1.5) - 15) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 80))
	{
		DrawText("No", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2, 30, GRAY);
	}
	else
	{
		DrawText("No", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2, 30, GOLD);
	}
}
void ExitLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	if (Mouse.y >= ((GetScreenHeight() / 1.5) - 10) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::EXIT;
		}
	}
	if (Mouse.y >= ((GetScreenHeight() / 1.5) - 15) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 80))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::TITLE;
		}
	}
}