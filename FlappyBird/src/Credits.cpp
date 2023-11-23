#include "Credits.h"
#include "GameLoop.h"

void DrawCredit(Vector2& Mouse)
{
	DrawText("Game and Textures made by Joan Manuel Rivas Cepeda", static_cast<int>(GetScreenWidth()) / 8, GetScreenHeight() / 2, 40, GOLD);
	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		DrawText("Go Back", static_cast<int>(GetScreenWidth()) / 3, static_cast<int>(GetScreenHeight()) / 1, 20, GRAY);
	}
	else
	{
		DrawText("Go Back", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 1, 20, GOLD);
	}

	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
	{
		DrawText("Play Game", static_cast<int>(GetScreenWidth()) / 1, static_cast<int>(GetScreenHeight()) / 1, 20, GRAY);
	}
	else
	{
		DrawText("Play Game", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 1, 20, GOLD);
	}
}
void CreditLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::TITLE;
		}
	}
	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::TUTORIAL;
		}
	}
}