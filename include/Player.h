#ifndef PLAYER_H
#define PLAYER_H

typedef struct PLAYER
{   
    //人物id
    int id;
    char* name;
    //toolnum[0]为道具总数，接下来一次为路障，机器娃娃,炸弹
    int toolnum[4];
    //任务点数
    int points;
    //资金
    int fund;
    //地点,[0,69],左上角为0
    int loc;
    //int prison;
    struct PLAYER*next;

}Player;
#endif