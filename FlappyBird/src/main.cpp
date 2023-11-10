#include <iostream>
#include "raylib.h"
void GameLoop();

int main()
{
	srand(time(NULL));
	SetExitKey(KEY_NULL);
	GameLoop();
}