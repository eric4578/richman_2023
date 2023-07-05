#ifndef START_H
#define START_H

#include"Player.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
int  start(Player *player);
void set_init_fund(Player *player, int fund);
int set_init_role(Player *player,char *s);
void initPlayer(Player *player, int id);
int get_set_fund();
void freePlayer(Player*p);
int getPlayerNumber();
static int PlayerNumber;

#endif