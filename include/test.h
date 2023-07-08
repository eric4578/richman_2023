#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include"Player.h"
void setMoney(char*arg2,char*arg3);
void setPoint(char*arg2,char*arg3);
void setItem(char*arg2,char*arg3,char*arg4);
void setBuff(char*arg2,char*arg3);
void setMap(char*arg2,char*arg3,char*arg4);
void setUnmap(char*arg2);
void setBomb(char*arg2);
void setBarrier(char*arg2);
void setPos(char*arg2,char*arg3);
void setStop(char*arg2,char*arg3);
int Dump_One_Player(FILE* fp, Player *p, int PlayerNumber,char*file_path);
// int Dump_Line(char * line,int line_num,char*file_path);
int dump_file(Player* p, int PlayerNumber, int preuser, char*file_path);
int Dump_line_overload();
int searchIndexfromId(int id);
int searchIndex(char*name);
#endif