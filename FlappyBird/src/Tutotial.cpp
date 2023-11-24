#include "Tutotial.h"
#include "GameLoop.h"



void TutotialLogic(Vector2& Mouse, GameScreen& currentScreen)
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

void DrawTutotial(Vector2& Mouse)
{

	DrawText("How to Play", GetScreenWidth() / 3, GetScreenHeight() / 9 - 50, 60, BLACK);
	DrawText("Press W to make the penguin fly" , GetScreenWidth() / 2 - 150 , GetScreenHeight() / 5 + 60, 20, BLACK);
	DrawText("Avoid the pipes and try to stay alive!", GetScreenWidth() / 2 - 170, GetScreenHeight() / 5 + 90, 20, BLACK);
	DrawText("Press The Back menu botton to go back to the main menu.", GetScreenWidth() / 2 - 270, GetScreenHeight() / 5 + 120, 20, BLACK);

	int goBackButtonX = static_cast<int>(GetScreenWidth()) / 2 - 80;
	int goBackButtonY = static_cast<int>(GetScreenHeight()) / 2 + 250;
	int goBackButtonWidth = 200;
	int goBackButtonHeight = 30;

	if (CheckButtonHovered(Mouse, goBackButtonX, goBackButtonY, goBackButtonWidth, goBackButtonHeight))
	{
		DrawText("Go Back Menu", goBackButtonX, goBackButtonY, 30, BLACK);
	}
	else
	{
		DrawText("Go Back Menu", goBackButtonX, goBackButtonY, 30, BLACK);
	}


}
