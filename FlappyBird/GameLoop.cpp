#include <iostream>
#include "Player.h"

void InitPlayer(Player& player);

void GameLoop()
{
	Player player;
	InitPlayer(player);
	const int height = 768;
	const int width = 1024;
	InitWindow(width, height, "Penguin Dream");

	int PipeX = GetScreenWidth();
	float DeltaTime = GetFrameTime();

	while (!WindowShouldClose())
	{


		int FreeSpace_A = rand() % ((GetScreenHeight()/2) - player.Height);
		int FreeSpace_B = rand() % ((GetScreenHeight() / 2) + player.Height);

		if (PipeX <= 0)
		{
			PipeX = GetScreenWidth() * (int)DeltaTime;
		}
		PipeX -= 1 * (int)GetFrameTime();

		if (player.Pos.y <= FreeSpace_A && player.Pos.x >= PipeX - (player.Width/2) && player.Pos.x <= PipeX + (player.Width / 2))
		{
			player.Pos.y += player.InitPos.y * DeltaTime;
			player.Pos.x += player.InitPos.x * DeltaTime;
		}

		if (IsKeyPressed(KEY_W) && player.Pos.y <= 0)
		{
			player.Pos.y += player.Speed * DeltaTime;
		}

		if (player.Pos.y > (GetScreenHeight()-50))
		{
			player.Pos.y -= 1.0f * DeltaTime;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(player.Pos.x, player.Pos.y, player.Width, player.Height, DARKBLUE);
		//Pipes
		DrawRectangle(PipeX,0, player.Width, FreeSpace_A, DARKGREEN); //Top
		DrawRectangle(PipeX, GetScreenHeight(), player.Width, FreeSpace_B, DARKGREEN); //Bottom

		EndDrawing();
	}
	
	CloseWindow();
}