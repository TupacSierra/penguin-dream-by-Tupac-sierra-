#include "Player.h"

void InitPlayer(Player& player)
{
	player.initPos = { 100, 384 };
	player.pos = {player.initPos.x, player.initPos.y};
	player.speed = 300;
	player.heingt = 40;
	player.width = 40;
	player.jump = false;
}