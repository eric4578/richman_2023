#include "update.h"
#include "map.h"
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
extern mapnode map[MAX_MAP_NUM];
/*step函数*/
int step(Player*player,int step)
{
    int i=0,flag=0;
    //更新旧节点的用户表
    while (i<4)
    {
        if(map[player->loc].user[i]==getPlayerch(player->id))
        {
            flag=1;
        }
        if(flag)
        {
            if(i<3)
            map[player->loc].user[i]=map[player->loc].user[i+1];
            else
            map[player->loc].user[i]='0';
        }
        i++;
    }
    updateMapNode(player->loc);
    //更新新节点的用户表
    player->loc+=step;
    i=3;
    while (i>0)
    {
        map[player->loc].user[i]=map[player->loc].user[i-1];
        i--;
    }
    map[player->loc].user[0]=getPlayerch(player->id);
    //特殊事件
    if(player->loc==PRISON)
    {
        //TODO
    }
    //判断新地是否有主,有则询问是否购买
    buyLand(player, player->loc); 
    updateMapNode(player->loc);
    return 0;
}

/*put block in [-10,10],and not in player*/
int putBlock(Player*player,int num)
{
    //TODO
    return 0;
}

/*clear tool in front 10*/
int robotClear(Player*player)
{
    //TODO
    return 0;
}

/*put bomb in [-10,10],and not in player and hospital*/
int putBomb(Player*player,int num)
{
    return 0;
}

/*包含更新状态的函数，用于每回合初处理各种效果和游戏中购买土地*/
/*生成随机数的函数*/
int get_roll_number()
{

    // 设置随机数生成器的种子为当前时间
    srand(time(NULL));

    // 生成随机数并打印
    return 1 + rand() % 6;

}


