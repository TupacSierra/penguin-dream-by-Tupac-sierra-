#include "Player.h"

void InitPlayer(Player& player)
{
	player.InitPos = { 100, 384 };
	player.Pos = {player.InitPos.x, player.InitPos.y};
	player.Speed = 300;
	player.Height = 40;
	player.Width = 40;
	player.Jump = false;
}