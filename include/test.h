#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include"Player.h"
int setMoney(char*arg2,char*arg3);
int setPoint(char*arg2,char*arg3);
int setItem(char*arg2,char*arg3,char*arg4);
int setBuff(char*arg2,char*arg3);
int setMap(char*arg2,char*arg3,char*arg4);
int setUnmap(char*arg2);
int setBomb(Player*player,char*arg2);
int setBarrier(Player*player,char*arg2);
int setPos(char*arg2,char*arg3);
int setQuit(char*arg2);
int setStop(char*arg2,char*arg3);
int Dump_One_Player(Player *p,char*file_path);
int Dump_Line(char * line,int line_num,char*file_path);
int dump_file(Player* p,char*file_path);
int Dump_line_overload();
#endif