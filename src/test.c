/*test包含测试函数，即set指令以及dump输出指令*/
#include"test.h"
#include "Player.h"
#include "map.h"
#include <string.h>
#include <stdlib.h>


extern Player players[MAX_PLAYER_NUM]; //玩家
extern mapnode map[MAX_MAP_NUM];//地图

static char NameToIndex[MAX_PLAYER_NUM + 1][10] = { // 玩家id和玩家名字的映射关系，1234分别和用户建立角色时的1234相同
        "",
        "Q",
        "A",
        "S",
        "J",
};

int searchIndex(char* name){
    for (int i =0;i<MAX_PLAYER_NUM;i++){
        if (strcmp(name, NameToIndex[players[i].id]) == 0 ){
            return i;
        }
    }
}

void setMoney(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].fund = atoi(arg3);
}
void setPoint(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].points = atoi(arg3);
}
void setItem(char*arg2,char*arg3,char*arg4)
{
    int index = searchIndex(arg2);
    int num = atoi(arg4);
    players[index].toolnum[0]+=num;
    players[index].toolnum[atoi(arg3)] += num;
}
void setBuff(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].buff = atoi(arg3);
}
void setMap(char*arg2,char*arg3,char*arg4)
{
    int index = searchIndex(arg3);
    map[atoi(arg2)].whose = players[index].id;
    map[atoi(arg2)].level = atoi(arg4);
}
void setUnmap(char*arg2)
{
    map[atoi(arg2)].whose = 0;
    map[atoi(arg2)].level = 0;
}
void setBomb(char*arg2)
{
    map[atoi(arg2)].item[3] = 1;
}
void setBarrier(char*arg2)
{
    map[atoi(arg2)].item[1] = 1;
}
void setPos(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    int nowPos = players[index].loc;

    char ch = arg2[0];

    for (int i=0;i<MAX_PLAYER_NUM;i++)
        if (map[nowPos].user[i] == ch ){
            for (int j=i;j<MAX_PLAYER_NUM;j++)
                map[nowPos].user[j]=map[nowPos].user[j+1];
            break;
        }
    int pos = atoi(arg3);
    players[index].loc = pos;
    char* tmp = arg3;
    strcat(tmp, map[atoi(arg2)].user);
    strcpy(map[atoi(arg2)].user, tmp);
}
void setStop(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].stop = atoi(arg3);
}