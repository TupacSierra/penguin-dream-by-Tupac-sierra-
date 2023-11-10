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
	
	int JumpCounter = 0;
	int FreeSpace_A = 0;
	int FreeSpace_B = 0;
	float PipeX = (float)GetScreenWidth();
	float FallSpeed = 250;
	bool PipeReset = true;
	
	

	while (!WindowShouldClose())
	{

		if (PipeReset == true)
		{
			PipeX = GetScreenWidth();
			do
			{
			FreeSpace_A = rand() % (GetScreenHeight()/2) - (player.Height*1.5);
			FreeSpace_B = rand() % (GetScreenHeight() /2) + (player.Height*1.5);
			} while (FreeSpace_A <= 0);
			
			PipeReset = false;
		}

		PipeX -= 200.0f * GetFrameTime();

		if (player.Pos.x >= (PipeX-player.Width/2) && player.Pos.x <= (PipeX+player.Width/2) && player.Pos.y <= FreeSpace_A || player.Pos.x >= (PipeX - player.Width / 2) && player.Pos.x <= (PipeX + player.Width / 2) && player.Pos.y >= (GetScreenHeight() - FreeSpace_B) || player.Pos.y > height)
		{
			player.Pos.y = player.InitPos.y;
			player.Pos.x = player.InitPos.x;
			PipeReset = true;
			player.Jump = false;
		}

		if (PipeX < 0)
		{
			PipeReset = true;
		}

		if (IsKeyPressed(KEY_W) && player.Pos.y > 0)
		{
			player.Jump = true;
			JumpCounter = 960;
		}

		if (player.Jump == true)
		{
			if (JumpCounter > 0)
			{
				player.Pos.y -= player.Speed * GetFrameTime();
			}
			JumpCounter--;
			if (JumpCounter == 0)
			{
				player.Jump = false;
			}
		}
		
		if (player.Jump == false)
		{
				player.Pos.y += FallSpeed * GetFrameTime();
		}
		

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(player.Pos.x, player.Pos.y, player.Width, player.Height, DARKBLUE);
		//Pipes
		DrawRectangle(PipeX,0, player.Width, FreeSpace_A, DARKGREEN); //Top
		DrawRectangle(PipeX, (GetScreenHeight()-FreeSpace_B), player.Width, FreeSpace_B, DARKGREEN); //Bottom

		DrawText("0.1", 990, 735, 30, WHITE);

		EndDrawing();
	}
	
	CloseWindow();
}