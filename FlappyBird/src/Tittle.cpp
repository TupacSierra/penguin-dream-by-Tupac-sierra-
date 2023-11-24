#pragma once

#include "Tittle.h"

void DrawTittle(Vector2& Mouse)
{

    //Game Tittle
    DrawText("Penguin Dream", static_cast<int>(GetScreenWidth()) / 2 - 200, static_cast<int>(GetScreenHeight()) / 2 - 200, 70, GOLD);

 
    // Play Button
    int playButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int playButtonY = static_cast<int>(GetScreenHeight()) / 2 - 50;
    int playButtonWidth = 100;
    int playButtonHeight = 30;

    if (CheckButtonHovered(Mouse, playButtonX, playButtonY, playButtonWidth, playButtonHeight))
    {
        DrawText("Play", playButtonX, playButtonY, 40, GRAY);
    }
    else
    {
        DrawText("Play", playButtonX, playButtonY, 40, GOLD);
    }

    // How to Play Button
    int howToPlayButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int howToPlayButtonY = static_cast<int>(GetScreenHeight()) / 2 + 5;
    int howToPlayButtonWidth = 100;
    int howToPlayButtonHeight = 30;

    if (CheckButtonHovered(Mouse, howToPlayButtonX, howToPlayButtonY, howToPlayButtonWidth, howToPlayButtonHeight))
    {
        DrawText("How to Play", howToPlayButtonX, howToPlayButtonY, 40, GRAY);
    }
    else
    {
        DrawText("How to Play", howToPlayButtonX, howToPlayButtonY, 40, GOLD);
    }

    // Credits Button
    int creditsButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int creditsButtonY = static_cast<int>(GetScreenHeight()) / 2 + 60;
    int creditsButtonWidth = 100;
    int creditsButtonHeight = 30;

    if (CheckButtonHovered(Mouse, creditsButtonX, creditsButtonY, creditsButtonWidth, creditsButtonHeight))
    {
        DrawText("Credits", creditsButtonX, creditsButtonY, 40, GRAY);
    }
    else
    {
        DrawText("Credits", creditsButtonX, creditsButtonY, 40, GOLD);
    }

    // Exit Button
    int exitButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int exitButtonY = static_cast<int>(GetScreenHeight()) / 2 + 115;
    int exitButtonWidth = 90;
    int exitButtonHeight = 30;

    if (CheckButtonHovered(Mouse, exitButtonX, exitButtonY, exitButtonWidth, exitButtonHeight))
    {
        DrawText("Exit", exitButtonX, exitButtonY, 40, GRAY);
    }
    else
    {
        DrawText("Exit", exitButtonX, exitButtonY, 40, GOLD);
    }
}

void TittleLogic(Vector2& Mouse, GameScreen& currentScreen)
{
    // Play Button
    int playButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int playButtonY = static_cast<int>(GetScreenHeight()) / 2 - 50;
    int playButtonWidth = 100;
    int playButtonHeight = 30;

    if (CheckButtonClicked(Mouse, playButtonX, playButtonY, playButtonWidth, playButtonHeight))
    {
        currentScreen = GameScreen::GAME;
    }

    // How to Play Button
    int howToPlayButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int howToPlayButtonY = static_cast<int>(GetScreenHeight()) / 2 + 5;
    int howToPlayButtonWidth = 100;
    int howToPlayButtonHeight = 30;

    if (CheckButtonClicked(Mouse, howToPlayButtonX, howToPlayButtonY, howToPlayButtonWidth, howToPlayButtonHeight))
    {
        currentScreen = GameScreen::TUTORIAL;
    }

    // Credits Button
    int creditsButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int creditsButtonY = static_cast<int>(GetScreenHeight()) / 2 + 60;
    int creditsButtonWidth = 100;
    int creditsButtonHeight = 30;

    if (CheckButtonClicked(Mouse, creditsButtonX, creditsButtonY, creditsButtonWidth, creditsButtonHeight))
    {
        currentScreen = GameScreen::CREDIT;
    }

    // Exit Button
    int exitButtonX = static_cast<int>(GetScreenWidth()) / 2 - 40;
    int exitButtonY = static_cast<int>(GetScreenHeight()) / 2 + 115;
    int exitButtonWidth = 90;
    int exitButtonHeight = 30;

    if (CheckButtonClicked(Mouse, exitButtonX, exitButtonY, exitButtonWidth, exitButtonHeight))
    {
        currentScreen = GameScreen::ASKEXIT;
    }
}

bool CheckButtonHovered(Vector2 mouse, int x, int y, int width, int height)
{
    return (mouse.x >= x && mouse.x <= x + width && mouse.y >= y && mouse.y <= y + height);
}

bool CheckButtonClicked(Vector2 mouse, int x, int y, int width, int height)
{
    return (CheckButtonHovered(mouse, x, y, width, height) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
}