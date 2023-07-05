#ifndef UPDATE_H
#define UPDATE_H

#include"Player.h"
int step(Player*player,int step);
//int step(Player*player,char* step);
Player* changePlayer(Player*Player);
int get_roll_number();
int putBlock(Player*player,int num);
int robotClear(Player*player);
int putBomb(Player*player,int num);
#endif