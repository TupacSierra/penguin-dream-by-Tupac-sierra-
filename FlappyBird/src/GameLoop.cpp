#include "GameLoop.h"

static Player player;
static float backGroundSpeed = 0;
static float midGroundSpeed = 0;
static float foreGroundSpeed = 0;
static bool pipeReset = true;
static Texture2D backGround;
static Texture2D midGround;
static Texture2D foreGround;
const int heightScreen = 768;
const int widthScreen = 1024;


const float gravity = 650.0f;
const float jumpSpeed = 300.0f;
float playerVelocityY = 0.0f;


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
        playerVelocityY = -jumpSpeed;
    }

    player.pos.y += playerVelocityY * GetFrameTime();
    playerVelocityY += gravity * GetFrameTime();
    
}
void HandleTubeMovementAndScoring()
{
    // Move the tubes to the left
    

    // Reset tubes when they go off-screen


    // Score when passing through a tube
  

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
   


}
