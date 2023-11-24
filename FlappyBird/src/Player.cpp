#include "Player.h"

void InitPlayer(Player& player)
{
	player.initPos = { 100, 384 };
	player.pos = {player.initPos.x, player.initPos.y};
	player.heingt = 40;
	player.width = 40;


}