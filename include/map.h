<<<<<<< HEAD
typedef struct mapNode{
    int loc_id;
    char whom;//0为无人空地
    int level;//0-3级
    int item[3];//bool 量，存在某一个道具，2为机器娃娃弃用
    char user[4];//在此地的玩家
    char ch;//显示字符
}mapnode;

static mapnode map[70];

#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_YELLOW  "\033[33m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN    "\033[36m"
#define ANSI_COLOR_RESET   "\033[0m"
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define RESET   7
=======
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


>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08


int printNode(mapnode node);
int initMap();
<<<<<<< HEAD
int printMap();
=======
int printMap();
int getcolor(char ch);
int updateMapNode(int index);
#endif
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
