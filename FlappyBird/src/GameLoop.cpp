#include <iostream>
#include "Player.h"

void InitPlayer(Player& player);

void GameLoop()
{
	Player player;
	Player player2;
	InitPlayer(player);
	InitPlayer(player2);
	const int height = 768;
	const int width = 1024;

	Texture2D Background = LoadTexture("res/BackGround.png");
	Texture2D Midground = LoadTexture("res/MidGround.png");
	Texture2D Foreground = LoadTexture("res/ForeGround.png");
	
	int JumpCounter = 0;
	int FreeSpace_A = 0;
	int FreeSpace_B = 0;
	float PipeX = (float)GetScreenWidth();
	float FallSpeed = 250;
	float BackgroundSpeed = 0;
	float MidgroundSpeed = 0;
	float ForegroundSpeed = 0;
	bool PipeReset = true;
	
	

	while (!WindowShouldClose())
	{
		BackgroundSpeed -= 0.01f;
		MidgroundSpeed -= 0.05f;
		ForegroundSpeed -= 0.1f;

		if (BackgroundSpeed <= -Background.width *2) BackgroundSpeed = 0;
		if (MidgroundSpeed <= -Midground.width *2) MidgroundSpeed = 0;
		if (ForegroundSpeed <= -Foreground.width *2) ForegroundSpeed = 0;
		

		if (PipeReset == true)
		{
			PipeX = GetScreenWidth();
			do
			{
			FreeSpace_A = rand() % (GetScreenHeight()/2);
			FreeSpace_B = rand() % (GetScreenHeight() /2);
			} while (FreeSpace_A - FreeSpace_B <= player.Height*1.5 ||  FreeSpace_B <= 160);
			
			PipeReset = false;
		}

		PipeX -= 200.0f * GetFrameTime();

		if (player.Pos.x >= (PipeX-player.Width/2) && player.Pos.x <= (PipeX+player.Width/2) && player.Pos.y <= FreeSpace_A || player.Pos.x >= (PipeX - player.Width / 2) && player.Pos.x <= (PipeX + player.Width / 2) && player.Pos.y >= (GetScreenHeight() - FreeSpace_B) || player.Pos.y > height)
		{
			player.Pos.y = player.InitPos.y;
			player.Pos.x = player.InitPos.x;
			PipeReset = true;
			player.Jump = false;
			BackgroundSpeed = 0;
			MidgroundSpeed = 0;
			ForegroundSpeed = 0;
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
				if (player.Pos.y < 0)
				{
					player.Pos.y = 0;
				}
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




		if (IsKeyPressed(KEY_UP) && player2.Pos.y > 0)
		{
			player2.Jump = true;
			JumpCounter = 960;
		}

		if (player2.Jump == true)
		{
			if (JumpCounter > 0)
			{
				player2.Pos.y -= player2.Speed * GetFrameTime();
				if (player2.Pos.y < 0)
				{
					player2.Pos.y = 0;
				}
			}
			JumpCounter--;
			if (JumpCounter == 0)
			{
				player2.Jump = false;
			}
		}

		if (player2.Jump == false)
		{
			player2.Pos.y += FallSpeed * GetFrameTime();
		}


		
		ClearBackground(BLACK);
		DrawTextureEx(Background, {BackgroundSpeed,0}, 0, 2, WHITE);
		DrawTextureEx(Background, {static_cast<float>(Background.width *2)+BackgroundSpeed,0}, 0, 2, WHITE);
		DrawRectangle(player.Pos.x, player.Pos.y, player.Width, player.Height, DARKBLUE);
		DrawRectangle(player2.Pos.x + 25, player2.Pos.y, player2.Width, player2.Height, DARKBLUE);
		//Pipes
		DrawRectangle(PipeX,0, player.Width, FreeSpace_A, DARKGREEN); //Top
		DrawRectangle(PipeX, (GetScreenHeight()-FreeSpace_B), player.Width, FreeSpace_B, DARKGREEN); //Bottom

		DrawText("0.1", 990, 735, 30, WHITE);

		EndDrawing();
	}
	
	UnloadTexture(Background);
	UnloadTexture(Foreground);
	UnloadTexture(Midground);
	CloseWindow();
}