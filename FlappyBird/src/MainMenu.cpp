#include "raylib.h"

typedef enum GameScreen { TITLE = 0, GAME, CREDIT, EXIT } GameScreen;


int GameLoop();

void MainMenu() {
	const int height = 768;
	const int width = 1024;
	Vector2 Mouse = { -100.0f, -100.0f };

	int option = 0;

	InitWindow(width, height, "Samurai Rush");

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
					currentScreen = GAME;
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
		case GAME:
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
					currentScreen = TITLE;
					GameLoop();
				}
			}
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
					currentScreen = GAME;
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
		ClearBackground(MAROON);

		switch (currentScreen)
		{
		case TITLE:
			DrawText("Samurai Rush", GetScreenWidth() / 3.3, GetScreenHeight() / 4, 60, GOLD);
			DrawText("Use the Mouse and Left Click", GetScreenWidth() / 2.6, GetScreenHeight() / 1.1, 15, GRAY);
			if (Mouse.y >= (GetScreenHeight() / 2 - 20) && Mouse.y <= (GetScreenHeight() / 2 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 60))
			{
				DrawText("Play", GetScreenWidth() / 2.2, GetScreenHeight() / 2, 30, GRAY);
			}
			else
			{
				DrawText("Play", GetScreenWidth() / 2.2, GetScreenHeight() / 2, 30, GOLD);
			}

			if (Mouse.y >= (GetScreenHeight() / 1.7 - 20) && Mouse.y <= (GetScreenHeight() / 1.7 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 100))
			{
				DrawText("Credits", GetScreenWidth() / 2.2, GetScreenHeight() / 1.7, 30, GRAY);
			}
			else
			{
				DrawText("Credits", GetScreenWidth() / 2.2, GetScreenHeight() / 1.7, 30, GOLD);
			}
			if (Mouse.y >= (GetScreenHeight() / 1.5 - 20) && Mouse.y <= (GetScreenHeight() / 1.5 + 30) && Mouse.x >= ((GetScreenWidth() / 2.1) - 40) && Mouse.x <= ((GetScreenWidth() / 2.1) + 50))
			{
				DrawText("Exit", GetScreenWidth() / 2.2, GetScreenHeight() / 1.5, 30, GRAY);
			}
			else
			{
				DrawText("Exit", GetScreenWidth() / 2.2, GetScreenHeight() / 1.5, 30, GOLD);
			}

			break;
		case GAME:
			DrawText("How to Play", GetScreenWidth() / 3, GetScreenHeight() / 9, 60, GOLD);
			DrawText("To play the game, you will be using the Mouse and its Left and Right clicks", GetScreenWidth() / 9, GetScreenHeight() / 5, 20, GOLD);
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				DrawText("Go Back", GetScreenWidth() / 2.5, GetScreenHeight() / 1.1, 20, GRAY);
			}
			else
			{
				DrawText("Go Back", GetScreenWidth() / 2.5, GetScreenHeight() / 1.1, 20, GOLD);
			}

			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
			{
				DrawText("Play Game", GetScreenWidth() / 1.8, GetScreenHeight() / 1.1, 20, GRAY);
			}
			else
			{
				DrawText("Play Game", GetScreenWidth() / 1.8, GetScreenHeight() / 1.1, 20, GOLD);
			}
			break;
		case CREDIT:
			DrawText("Game made by Joan Manuel Rivas Cepeda", GetScreenWidth() / 7.8, GetScreenHeight() / 2, 40, GOLD);
			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 10) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				DrawText("Go Back", GetScreenWidth() / 2.5, GetScreenHeight() / 1.1, 20, GRAY);
			}
			else
			{
				DrawText("Go Back", GetScreenWidth() / 2.5, GetScreenHeight() / 1.1, 20, GOLD);
			}

			if (Mouse.y >= ((GetScreenHeight() / 1.1) - 15) && Mouse.y <= ((GetScreenHeight() / 1.1) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 100))
			{
				DrawText("Play Game", GetScreenWidth() / 1.8, GetScreenHeight() / 1.1, 20, GRAY);
			}
			else
			{
				DrawText("Play Game", GetScreenWidth() / 1.8, GetScreenHeight() / 1.1, 20, GOLD);
			}


			break;
		case EXIT:
			DrawText("You sure you want to close the game ?", GetScreenWidth() / 7.5, GetScreenHeight() / 2, 40, GOLD);
			if (Mouse.y >= ((GetScreenHeight() / 1.5) - 10) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 2.5) - 30) && Mouse.x <= ((GetScreenWidth() / 2.5) + 90))
			{
				DrawText("Yes", GetScreenWidth() / 2.5, GetScreenHeight() / 1.5, 30, GRAY);
			}
			else
			{
				DrawText("Yes", GetScreenWidth() / 2.5, GetScreenHeight() / 1.5, 30, GOLD);
			}

			if (Mouse.y >= ((GetScreenHeight() / 1.5) - 15) && Mouse.y <= ((GetScreenHeight() / 1.5) + 15) && Mouse.x >= ((GetScreenWidth() / 1.8) - 15) && Mouse.x <= ((GetScreenWidth() / 1.8) + 80))
			{
				DrawText("No", GetScreenWidth() / 1.8, GetScreenHeight() / 1.5, 30, GRAY);
			}
			else
			{
				DrawText("No", GetScreenWidth() / 1.8, GetScreenHeight() / 1.5, 30, GOLD);
			}
			break;
		default:
			break;
		}
		EndDrawing();
	}
	CloseWindow();
}