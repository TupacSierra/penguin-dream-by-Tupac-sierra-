#include <iostream>
#include "raylib.h"
void MainMenu();

int main()
{
	srand(time(NULL));
	SetExitKey(KEY_NULL);
	MainMenu();
}