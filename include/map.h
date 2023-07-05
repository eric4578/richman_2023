#ifndef MAP_H
#define MAP_H
#include "global.h"


typedef struct mapNode{/*whom->whose;user->player;*/
    int loc_id;
    int price; // -1不可购买
    int whose; // '0'为无人空地，1234对应不同玩家
    int level; // '0'-'3'级
    int item[MAX_TOOL_NUM]; // bool 量，0弃用，存在某一个道具，2为机器娃娃弃用
    char user[MAX_PLAYER_NUM]; // 在此地的玩家,初始为0,user[0]是最后到的玩家
    char ch;// 显示字符
    int color;
}mapnode;




int printNode(mapnode node);
int initMap();
int printMap();
int getcolor(char ch);
int updateMapNode(int index);
#endif