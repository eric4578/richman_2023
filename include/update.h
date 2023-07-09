#ifndef UPDATE_H
#define UPDATE_H

#include"Player.h"
int step(Player*player,int step);
//int step(Player*player,char* step);
Player* changePlayer(Player*Player);
int get_roll_number();
int putBlock(Player*player,int num);
int robotClear(Player*player);
int payRent(int from,int to);
int updatePlayer(Player*player);
int getGift(Player*player);
int dead(Player*player);
int get_buff_round();
#endif