#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include "map.h"
#include "Player.h"
int buyLand(Player* player, int index) ;
int sellLand(Player* player, int index) ;

int query(Player * player);
int bomb(Player * player);
int block(Player * player);
int robot(Player * player);
void help();
void quit();
#endif
