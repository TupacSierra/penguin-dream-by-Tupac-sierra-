#include "raylib.h"
#include "GameLoop.h"
typedef enum GameScreen { TITLE = 0, TUTORIAL,GAME, CREDIT, EXIT } GameScreen;


void DrawGame();

void MainMenu() {
	const int height = 768;
	const int width = 1024;
	Vector2 Mouse = { -100.0f, -100.0f };

	

	InitWindow(width, height, "Penguin Dream");

	GameScreen currentScreen = TITLE;

	while (!WindowShouldClose())
	{
		Mouse = GetMousePosition();
		switch (currentScreen)
		{
		case TITLE:
			if (Mouse.y >= (GetScreenHeight() / 2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 60))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = TUTORIAL;
				
				}
			}
			if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 100))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = CREDIT;
				}
			}
			if (Mouse.y >= (GetScreenHeight() / 1.5 - 20) && Mouse.y <= (GetScreenHeight() / 1.5 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 50))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = EXIT;
				}
			}
			break;
		case TUTORIAL:
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = TITLE;
				}
			}
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = GAME;
					InitGame();
	
				}
			}
			break;
		case GAME:
			UpdateGame();

			break;
		case CREDIT:
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = TITLE;
				}
			}
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = TUTORIAL;
				}
			}
			break;
		case EXIT:
			if (Mouse.y >= ((GetScreenHeight() / 1.5) - 10) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					CloseWindow();
				}
			}
			if (Mouse.y >= ((GetScreenHeight() / 1.5) - 15) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 80))
			{
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					currentScreen = TITLE;
				}
			}
			break;
		default:
			break;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		switch (currentScreen)
		{
		case TITLE:
			DrawText("Penguin Dream", static_cast<int> (width) / 3, static_cast<int> (height) / 4, 60, GOLD);
			DrawText("Use the Mouse and Left Click", static_cast<int>(GetScreenWidth()) / 2 - 20, static_cast<int>(GetScreenHeight()) / 2 + 245, 15, GRAY);
			if (Mouse.y >= (GetScreenHeight() / 2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 30) && Mouse.x >= ((GetScreenWidth() / 2) - 40) && Mouse.x <= ((GetScreenWidth() / 2) + 60))
			{
				DrawText("Play", static_cast<int>(GetScreenWidth()) / 2, GetScreenHeight() / 2 -50, 30, GRAY);
			}
			else
			{
				DrawText("Play", static_cast<int>(GetScreenWidth()) / 2, GetScreenHeight() / 2 - 50, 30, GOLD);
			}

			if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 100))
			{
				DrawText("Credits", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2 -20, 30, GRAY);
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

			break;
		case TUTORIAL:
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

			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
			{
				DrawText("Play Game", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 1, 20, GRAY);
			}
			else
			{
				DrawText("Play Game", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 1, 20, GOLD);
			}
			break;
		case GAME:
			DrawGame();
			break;
		case CREDIT:
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


			break;
		case EXIT:
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
				DrawText("No", static_cast<int>( GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2, 30, GRAY);
			}
			else
			{
				DrawText("No", static_cast<int>(GetScreenWidth()) / 2, static_cast<int>(GetScreenHeight()) / 2, 30, GOLD);
			}
			break;
		default:
			break;
		}
		EndDrawing();
	}
	CloseWindow();
}