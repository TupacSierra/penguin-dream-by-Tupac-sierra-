#include "Exit.h"
#include "GameLoop.h"

void DrawExit(Vector2& Mouse)
{
	DrawText("You sure you want to close the game ?", static_cast<int>(GetScreenWidth()) / 8, GetScreenHeight() / 2, 40, GOLD);

	int yesButtonX = static_cast<int>(GetScreenWidth()) / 2 - 80;
	int yesButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int yesButtonWidth = 60;
	int yesButtonHeight = 30;

	if (CheckButtonHovered(Mouse, yesButtonX, yesButtonY, yesButtonWidth, yesButtonHeight))
	{
		DrawText("Yes", yesButtonX, yesButtonY, 30, GRAY);
	}
	else
	{
		DrawText("Yes", yesButtonX, yesButtonY, 30, GOLD);
	}


	int noButtonX = static_cast<int>(GetScreenWidth()) / 2 + 80;
	int noButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int noButtonWidth = 35;
	int noButtonHeight = 30;

	if (CheckButtonHovered(Mouse, noButtonX, noButtonY, noButtonWidth, noButtonHeight))
	{
		DrawText("No", noButtonX, noButtonY, 30, GRAY);
	}
	else
	{
		DrawText("No", noButtonX, noButtonY, 30, GOLD);
	}


}
void ExitLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	int yesButtonX = static_cast<int>(GetScreenWidth()) / 2 - 80;
	int yesButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int yesButtonWidth = 60;
	int yesButtonHeight = 30;

	if (CheckButtonClicked(Mouse, yesButtonX, yesButtonY, yesButtonWidth, yesButtonHeight))
	{
		currentScreen = GameScreen::EXIT;
	}

	int noButtonX = static_cast<int>(GetScreenWidth()) / 2 + 80;
	int noButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int noButtonWidth = 35;
	int noButtonHeight = 30;

	if (CheckButtonClicked(Mouse, noButtonX, noButtonY, noButtonWidth, noButtonHeight))
	{
		currentScreen = GameScreen::TITLE;
	}


}