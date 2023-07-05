#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"

static char NAME_FROM_ID[MAX_PLAYER_NUM + 1][10] = { // 玩家id和玩家名字的映射关系，1234分别和用户建立角色时的1234相同
    "",
    "钱夫人",
    "阿土伯",
    "孙小美",
    "金贝贝",
};

typedef struct PLAYER
{   
    int id;    // 人物id
    int toolnum[MAX_TOOL_NUM];   // toolnum[0]为道具总数，接下来依次为路障，机器娃娃,炸弹的道具数
    int fund;       // 资金
    int points;    // 任务点数
    int loc;     //地点,[0,69],左上角为0
    int stop;   // 停止的回合数，如在医院、监狱
    int buff;    // 财神buff剩余时间
    int alive; // 玩家是否存活,1为存活
    int house[MAX_MAP_NUM];    // 储存玩家房产，下标为地块编号，-1不拥有，0123分别表示不同等级地产
}Player;
char getPlayerch(int id);
#endif