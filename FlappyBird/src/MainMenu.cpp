#include "raylib.h"
#include "GameLoop.h"
#include "Tittle.h"
#include "Tutotial.h"
#include "Credits.h"
#include "Exit.h"

void MainMenu() {
    const int height = 768;
    const int width = 1024;
    Vector2 Mouse = { -100.0f, -100.0f };

    InitWindow(width, height, "Penguin Dream");

    GameScreen currentScreen = GameScreen::TITLE;
    bool isGameOn = true;

    // Initialize the game state outside of the game loop
    InitGame();

    while (!WindowShouldClose() && isGameOn)
    {
        Mouse = GetMousePosition();

        switch (currentScreen)
        {
        case GameScreen::TITLE:
            TittleLogic(Mouse, currentScreen);
            break;
        case GameScreen::TUTORIAL:
            TutotialLogic(Mouse, currentScreen);
            break;
        case GameScreen::GAME:
            UpdateGame(); 
            break;
        case GameScreen::CREDIT:
            CreditLogic(Mouse, currentScreen);
            break;
        case GameScreen::ASKEXIT:
            ExitLogic(Mouse, currentScreen);
            break;
        case GameScreen::EXIT:
            isGameOn = false;
            break;
        default:
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (currentScreen) {
        case GameScreen::TITLE:
            DrawTittle(Mouse);
            break;
        case GameScreen::TUTORIAL:
            DrawTutotial(Mouse);
            break;
        case GameScreen::GAME:
            DrawGame();
            break;
        case GameScreen::CREDIT:
            DrawCredit(Mouse);
            break;
        case GameScreen::ASKEXIT:
            DrawExit(Mouse);
            break;
        default:
            break;
        }
        EndDrawing();
       
    }

   

    ExitGame();
    CloseWindow();
}
