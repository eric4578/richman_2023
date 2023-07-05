#ifndef TOOL_H
#define TOOL_H
#include"Player.h"
#include<stdio.h>

int buyTool(Player* player);
void buy_one_tool(Player*player,char ch);
void buyBlock(Player*player);
void buyRobot(Player*player);
void buyBomb(Player*player);

#endif