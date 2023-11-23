#include <iostream>
#include "raylib.h"
void MainMenu();

int main()
{
	srand((unsigned int)time(NULL));
	SetExitKey(KEY_NULL);
	MainMenu();
}