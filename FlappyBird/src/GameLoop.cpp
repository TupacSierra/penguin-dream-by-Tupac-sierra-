#include "GameLoop.h"

static Player player;

static int JumpCounter = 0;
static int FreeSpace_A = 0;
static int FreeSpace_B = 0;
static float PipeX = 0;
static float FallSpeed = 250;
static float BackgroundSpeed = 0;
static float MidgroundSpeed = 0;
static float ForegroundSpeed = 0;
static bool PipeReset = true;
static Texture2D Background;
static Texture2D Midground;
static Texture2D Foreground;
 const int height = 768;
 const int width = 1024;

void InitPlayer(Player& player);
void InitGame()
{
	InitPlayer(player);
	Background = LoadTexture("res/BackGround.png");
	Midground = LoadTexture("res/MidGround.png");
	Foreground = LoadTexture("res/ForeGround.png");

	JumpCounter = 0;
	FreeSpace_A = 0;
	FreeSpace_B = 0;
	PipeX = (float)GetScreenWidth();
	FallSpeed = 250;
	BackgroundSpeed = 0;
	MidgroundSpeed = 0;
	ForegroundSpeed = 0;
	PipeReset = true;
}
void ExitGame()
{
	UnloadTexture(Background);
	UnloadTexture(Foreground);
	UnloadTexture(Midground);

}

void UpdateGame()
{
	BackgroundSpeed -= 0.01f;
	MidgroundSpeed -= 0.05f;
	ForegroundSpeed -= 0.1f;

	if (BackgroundSpeed <= -Background.width * 2) BackgroundSpeed = 0;
	if (MidgroundSpeed <= -Midground.width * 2) MidgroundSpeed = 0;
	if (ForegroundSpeed <= -Foreground.width * 2) ForegroundSpeed = 0;


	if (PipeReset == true)
	{

		int result;
		PipeX = static_cast<float>(GetScreenWidth());
		do
		{
			FreeSpace_A = rand() % (GetScreenHeight() / 2);
			FreeSpace_B = rand() % (GetScreenHeight() / 2);
			result = FreeSpace_A - FreeSpace_B;
		} while (result <= player.Height * 1.5 || FreeSpace_B <= 160);

		PipeReset = false;
	}

	PipeX -= 200.0f * GetFrameTime();

	if (player.Pos.x >= (PipeX - player.Width / 2) && player.Pos.x <= (PipeX + player.Width / 2) && player.Pos.y <= FreeSpace_A || player.Pos.x >= (PipeX - player.Width / 2) && player.Pos.x <= (PipeX + player.Width / 2) && player.Pos.y >= (GetScreenHeight() - FreeSpace_B) || player.Pos.y > height)
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




}

void DrawGame()
{

	DrawTextureEx(Background, { BackgroundSpeed,0 }, 0, 2, WHITE);
	DrawTextureEx(Background, { static_cast<int>(Background.width * 2) + BackgroundSpeed,0 }, 0, 2, WHITE);
	DrawRectangle(static_cast<int>(player.Pos.x), static_cast<int>(player.Pos.y), static_cast<int>(player.Width), static_cast<int>(player.Height), DARKBLUE);
	//Pipes
	DrawRectangle(static_cast<int>(PipeX), 0, static_cast<int>(player.Width), FreeSpace_A, DARKGREEN); //Top
	DrawRectangle(static_cast<int>(PipeX), (GetScreenHeight() - FreeSpace_B), static_cast<int>(player.Width), FreeSpace_B, DARKGREEN); //Bottom

	DrawText("0.1", 990, 735, 30, WHITE);

}
