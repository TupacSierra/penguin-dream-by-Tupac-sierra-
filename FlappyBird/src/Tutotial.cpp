#include "Tutotial.h"
#include "GameLoop.h"



void TutotialLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			currentScreen = GameScreen::TITLE;
		}
	}
	
}

void DrawTutotial(Vector2& Mouse)
{
	DrawText("How to Play", GetScreenWidth() / 3, GetScreenHeight() / 9, 60, GOLD);
	DrawText("To play the game, you will be using the W and the Mouse to use the Menu", GetScreenWidth() / 9, GetScreenHeight() / 5, 20, GOLD);
	if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
	{
		DrawText("Go Back", static_cast<int>(GetScreenWidth()) / 3, static_cast<int>(GetScreenHeight()) / 1, 20, GRAY);
	}
	else
	{
		DrawText("Go Back", static_cast<int>(GetScreenWidth()) / 3, static_cast<int>(GetScreenHeight()) / 1, 20, GOLD);
	}


}