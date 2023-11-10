#include "Player.h"

void InitPlayer(Player& player)
{
	player.InitPos = { 100, 384 };
	player.Pos = {player.InitPos.x, player.InitPos.y};
	player.Speed = 10;
	player.Height = 40;
	player.Width = 40;
}