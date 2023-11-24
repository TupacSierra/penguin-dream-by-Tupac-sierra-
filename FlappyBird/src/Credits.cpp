#include "Credits.h"
#include "GameLoop.h"


void DrawCredit(Vector2& Mouse)
{
	DrawText("Game and Textures made by Joan Manuel Rivas Cepeda", static_cast<int>(GetScreenWidth()) / 2 - 250, GetScreenHeight() / 2 , 20, GOLD);
	DrawText("Game Develop Tupac Sierra", static_cast<int>(GetScreenWidth()) / 2 - 110, GetScreenHeight() / 2 + 20, 20, GOLD);


	int goBackButtonX = static_cast<int>(GetScreenWidth()) / 2  - 80;
	int goBackButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int goBackButtonWidth = 200;
	int goBackButtonHeight = 30;

	if (CheckButtonHovered(Mouse, goBackButtonX, goBackButtonY, goBackButtonWidth, goBackButtonHeight))
	{
		DrawText("Go Back Menu", goBackButtonX, goBackButtonY, 30, GRAY);
	}
	else
	{
		DrawText("Go Back Menu", goBackButtonX, goBackButtonY, 30, GOLD);
	}
}
void CreditLogic(Vector2& Mouse, GameScreen& currentScreen)
{
	int goBackButtonX = static_cast<int>(GetScreenWidth()) / 2 - 80;
	int goBackButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int goBackButtonWidth = 200;
	int goBackButtonHeight = 30;

	if (CheckButtonClicked(Mouse, goBackButtonX, goBackButtonY, goBackButtonWidth, goBackButtonHeight))
	{
		currentScreen = GameScreen::TITLE;
	}
}

