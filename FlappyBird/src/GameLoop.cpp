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

bool scoredForTube = false;
int score = 0;
Vector2 playerDestination;


bool CheckCollisionWithTubes() {
   
    return false; 
}

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
    // Move the background, midground, and foreground
    BackgroundSpeed -= 0.01f;
    MidgroundSpeed -= 0.05f;
    ForegroundSpeed -= 0.1f;

    if (BackgroundSpeed <= -Background.width * 2) BackgroundSpeed = 0;
    if (MidgroundSpeed <= -Midground.width * 2) MidgroundSpeed = 0;
    if (ForegroundSpeed <= -Foreground.width * 2) ForegroundSpeed = 0;

    // Move the tubes to the left
    PipeX -= 200.0f * GetFrameTime();

    // Check if the player collided or went out of bounds
    if (player.Pos.y > height || CheckCollisionWithTubes()) {
        // Handle game over state
        // You might want to set your game state accordingly
        // gameState = GAME_OVER;
        player.Pos.y = player.InitPos.y;
        player.Pos.x = player.InitPos.x;
        PipeReset = true;
        player.Jump = false;
        BackgroundSpeed = 0;
        MidgroundSpeed = 0;
        ForegroundSpeed = 0;
        // Additional logic for game over can be added here
    }

    // If the player presses W, initiate a jump
    if (IsKeyPressed(KEY_W) && player.Pos.y > 0) {
        player.Jump = true;
        JumpCounter = 960;
    }

    // Handle player jump
    if (player.Jump == true) {
        if (JumpCounter > 0) {
            player.Pos.y -= player.Speed * GetFrameTime();
            if (player.Pos.y < 0) {
                player.Pos.y = 0;
            }
        }
        JumpCounter--;
        if (JumpCounter == 0) {
            player.Jump = false;
        }
    }

    // If the player is not jumping, apply falling speed
    if (player.Jump == false) {
        player.Pos.y += FallSpeed * GetFrameTime();
    }

    // Handle tube movement and scoring
    HandleTubeMovementAndScoring();

    // Update the player destination for rendering
    playerDestination.x = player.Pos.x;
    playerDestination.y = player.Pos.y;
}
void HandleTubeMovementAndScoring()
{
    // Move the tubes to the left
    PipeX -= 200.0f * GetFrameTime();

    // Reset tubes when they go off-screen
    if (PipeX + player.Width <= 0) {
        PipeX = static_cast<float>(GetScreenWidth());
        scoredForTube = false;
    }

    // Score when passing through a tube
    if (PipeX + player.Width <= 0) {
        PipeX = static_cast<float>(GetScreenWidth());
        scoredForTube = false;
    }

    // Check for collisions with the tubes
    bool collided = CheckCollisionWithTubes();
    if (collided) {
        // Handle collision logic
        // You might want to set your game state accordingly
        // gameState = GAME_OVER;
        player.Pos.y = player.InitPos.y;
        player.Pos.x = player.InitPos.x;
        PipeReset = true;
        player.Jump = false;
        BackgroundSpeed = 0;
        MidgroundSpeed = 0;
        ForegroundSpeed = 0;
        // Additional logic for game over can be added here
    }
}
void DrawGame()
{

	DrawTextureEx(Background, { BackgroundSpeed,0 }, 0, 2, WHITE);
	DrawTextureEx(Background, { static_cast<int>(Background.width * 2) + BackgroundSpeed,0 }, 0, 2, WHITE);
    DrawRectangle(static_cast<int>(player.Pos.x), static_cast<int>(player.Pos.y), static_cast<int>(player.Width), static_cast<int>(player.Height), DARKBLUE);
	//Pipes
    DrawRectangle(static_cast<int>(PipeX), 0, static_cast<int>(player.Width), FreeSpace_A, DARKGREEN); // Top
    DrawRectangle(static_cast<int>(PipeX), (GetScreenHeight() - FreeSpace_B), static_cast<int>(player.Width), FreeSpace_B, DARKGREEN); // Bottom


}
