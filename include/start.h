#ifndef START_H
#define START_H

#include"Player.h"
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
<<<<<<< HEAD
Player* start();
void set_init_fund(Player *player, int fund);
Player *set_init_role(char *s);
void initPlayer(Player *player, int id);
int get_set_fund();
void freePlayer(Player*p);
static int PlayerNumber=0;
=======
int  start(Player *player);
void set_init_fund(Player *player, int fund);
int set_init_role(Player *player,char *s);
void initPlayer(Player *player, int id);
int get_set_fund();
void freePlayer(Player*p);
int getPlayerNumber();
static int PlayerNumber;
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08

#endif