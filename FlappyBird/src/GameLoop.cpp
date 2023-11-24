#include "GameLoop.h"

static Player player;

static int jumpCounter = 0;
static int freeSpace_A = 0;
static int freeSpace_B = 0;
static float pipeX = 0;
static float fallSpeed = 250;
static float backGroundSpeed = 0;
static float midGroundSpeed = 0;
static float foreGroundSpeed = 0;
static bool pipeReset = true;
static Texture2D backGround;
static Texture2D midGround;
static Texture2D foreGround;
const int heightScreen = 768;
const int widthScreen = 1024;


const float gravity = 1000.0f;
const float jumpSpeed = 500.0f;
const float jumpHeight = 100.0f;


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
	backGround = LoadTexture("res/BackGround.png");
	midGround = LoadTexture("res/MidGround.png");
	foreGround = LoadTexture("res/ForeGround.png");

	jumpCounter = 0;
	freeSpace_A = 0;
	freeSpace_B = 0;
	pipeX = (float)GetScreenWidth();
	fallSpeed = 250;
	backGroundSpeed = 0;
	midGroundSpeed = 0;
	foreGroundSpeed = 0;
	pipeReset = true;
}

void ExitGame()
{
    UnloadTexture(backGround);
    UnloadTexture(foreGround);
    UnloadTexture(midGround);
}

void UpdateGame()
{
    // Move the background, midground, and foreground
    backGroundSpeed -= 0.001f;
    midGroundSpeed -= 0.009f;
    foreGroundSpeed -= 0.02f;

    if (backGroundSpeed <= -backGround.width * 2) backGroundSpeed = 0;
    if (midGroundSpeed <= -midGround.width * 2) midGroundSpeed = 0;
    if (foreGroundSpeed <= -foreGround.width * 2) foreGroundSpeed = 0;



    if (IsKeyPressed(KEY_SPACE) && !player.jump)
    {
        player.jump = true;
        player.jumpSpeed = jumpSpeed;

    }

    if (player.jump == true)
    {
        if (jumpCounter > 0)
        {
            player.pos.y -= player.speed * GetFrameTime();
            if (player.pos.y < 0)
            {
                player.pos.y = 0;
            }
        }
    }

    jumpCounter--;

    if (jumpCounter == 0)
    {
        player.jump = false;

        if (player.pos.y > heightScreen - player.heingt)
        {
            player.pos.y = heightScreen - player.heingt;
        }
    }

    if (player.jump == false)
    {
        player.pos.y += fallSpeed * GetFrameTime();
        if (player.pos.y > heightScreen - player.heingt)
        {
            player.pos.y = heightScreen - player.heingt;
        }
    }

    if (!player.jump)
    {
        player.jumpSpeed += gravity * GetFrameTime();
        player.pos.y += player.jumpSpeed * GetFrameTime();
    }
    else
    {
        player.jumpSpeed -= gravity * GetFrameTime();

        player.pos.y -= player.jumpSpeed * GetFrameTime();


        if (player.pos.y <= player.initPos.y - jumpHeight || player.jumpSpeed < 0.0f)
        {
            player.pos.y = player.initPos.y - jumpHeight;
            player.jump = false;
        }
    }
    
}
void HandleTubeMovementAndScoring()
{
    // Move the tubes to the left
    pipeX -= 200.0f * GetFrameTime();

    // Reset tubes when they go off-screen
    if (pipeX + player.width <= 0) {
        pipeX = static_cast<float>(GetScreenWidth());
        scoredForTube = false;
    }

    // Score when passing through a tube
    if (pipeX + player.width <= 0) {
        pipeX = static_cast<float>(GetScreenWidth());
        scoredForTube = false;
    }

    // Check for collisions with the tubes
    bool collided = CheckCollisionWithTubes();
    if (collided) {
        // Handle collision logic
        // You might want to set your game state accordingly
        // gameState = GAME_OVER;
        player.pos.y = player.initPos.y;
        player.pos.x = player.initPos.x;
        pipeReset = true;
        player.jump = false;
        backGroundSpeed = 0;
        midGroundSpeed = 0;
        foreGroundSpeed = 0;
        // Additional logic for game over can be added here
    }
}
void DrawGame()
{

	DrawTextureEx(backGround, { backGroundSpeed,0 }, 0, 2, WHITE);
    DrawTextureEx(midGround, { midGroundSpeed,0 }, 0, 2, WHITE);
    DrawTextureEx(foreGround, { foreGroundSpeed,0 }, 0, 2, WHITE);
   

	DrawTextureEx(backGround, { static_cast<int>(backGround.width * 2) + backGroundSpeed,0 }, 0, 2, WHITE);
    DrawTextureEx(midGround, { static_cast<int>(midGround.width * 2) + midGroundSpeed,0 }, 0, 2, WHITE);
    DrawTextureEx(foreGround, { static_cast<int>(foreGround.width * 2) + foreGroundSpeed,0 }, 0, 2, WHITE);
  

    DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.width), static_cast<int>(player.heingt), RED);
	//Pipes
    DrawRectangle(static_cast<int>(pipeX), 0, static_cast<int>(player.width), freeSpace_A, DARKGREEN); // Top
    DrawRectangle(static_cast<int>(pipeX), (GetScreenHeight() - freeSpace_B), static_cast<int>(player.width), freeSpace_B, DARKGREEN); // Bottom


}
