#include "update.h"
#include "map.h"
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include"tool.h"
#include"func.h"
extern mapnode map[MAX_MAP_NUM];
extern Player players[MAX_PLAYER_NUM];

/*step函数*/
int step(Player*player,int step)
{
    int i=0,flag=0;
    step=step%MAX_MAP_NUM;
    //有没有道具
    for(i=1;i<=step;i++)
    {
        flag=((player->loc)+i)%MAX_MAP_NUM;
        if(map[flag].item[1]||map[flag].item[3])
        {
            if(map[flag].item[3])
                flag=solve_Bomb(player,flag);//处理炸弹
            else
                flag=solve_Block(player,flag);//处理障碍
            break;
        }
        flag=0;
    }
    if(flag==1) {
        printf("被阻\n");
        step=i;
    }
    else if(flag==3) {
        printf("被炸，进医院\n");
        step=HOSPITAL-(player->loc);//可以为负数
    }
    
    //更新旧节点的用户表
    i=0,flag=0;
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
    player->loc=(player->loc+step)%MAX_MAP_NUM;
    i=3;
    while (i>0)
    {
        map[player->loc].user[i]=map[player->loc].user[i-1];
        i--;
    }
    map[player->loc].user[0]=getPlayerch(player->id);
    //判断是否为监狱
    if(player->loc==PRISON)
    {
        printf("进入监狱\n");
        player->stop=2;
    }
    else if(player->loc==GIFTROOM)
    {
        printf("进入礼品屋\n");
        printf("选择1.奖金2000元；2.点数卡200点；3.财神buff\n");
        getGift(player);//todo
    }
    //是否为道具屋
    else if(player->loc==TOOLROOM)
    {
        buyTool(player);
    }
    //是否为魔法屋
    else if(player->loc==MAGICROOM)
    {
        printf("进入魔法屋\n");
        //useMagic(player);//TODO,magic room
    }
    //是否为矿地
    else if(player->loc<MAX_MAP_NUM&&player->loc>=(MAX_MAP_NUM-6))
    {
        int point=get_Mine_points(player->loc);
        player->points+=point;
        printf("进入矿地获得点数：%d\n",point);
    }
    //是否交租金
    if(map[player->loc].whose!=0&&map[player->loc].whose!=player->id)
    {
        payRent(player->id,map[player->loc].whose);//支付租金，金额转移
    }
    if(player->alive == 0) return 0;
    //判断新地是否有主,有则询问是否购买
    buyLand(player, player->loc); 
    updateMapNode(player->loc);
    return 0;
}

/*更新角色状态*/
int updatePlayer(Player*player)
{
    // if(player->buff>0)
    // {
    //     player->buff-=1;
    //     printUser(player);
    //     printf("剩余buff:%d\n", player->buff);
    // }
    if(player->stop>0)
    {
        player->stop-=1;
        printUser(player);
        printf("轮空：剩余%d轮\n", player->stop);
    }
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

/*支付租金,输入玩家id*/
int payRent(int from,int to)
{
    int flag=0;
    int from_index = -1;
    int to_index = -1;
    for(int i=0;i<MAX_PLAYER_NUM;i++)
    {
        if(players[i].id==from)
        {
            from_index=i;
            flag+=1;
        }
        if(players[i].id==to)
        {
            to_index=i;
            flag+=1;
        }
        if(flag==2) break;
    }
    if(players[from_index].buff<=0)//无buff
    {
        int index=players[from_index].loc;
        int rent = (map[index].price * (map[index].level + 1)) >> 1;
        if(players[from_index].fund>=rent && players[to_index].stop==0)//支付租金 
        {
            printf("支付%d租金给%s\n",rent,NAME_FROM_ID[players[to_index].id]);
            players[from_index].fund-=rent;
            players[to_index].fund+=rent;
        }
        
        else if(players[from_index].fund<rent)//玩家破产
        {
            dead(players+from_index);
        }
    }
    else
    {
        printf("财神保佑，免付租金\n");
    }
}

int dead(Player*player)
{
    for(int i=0;i<MAX_PLAYER_NUM;i++)
    {
        map[player->loc].user[i]=map[player->loc].user[i+1];
    }
    
    player->alive=0;
    //player->id=0;
    player->fund=0;
    player->buff=0;
    // player->loc=0;
    for(int i=0;i<MAX_TOOL_NUM;i++)
        player->toolnum[i]=0;
    player->points=0;
    player->stop=0;
    for(int i=0;i<MAX_MAP_NUM;i++)
    {
        if(player->house[i]!=-1)
        {
            player->house[i]=-1;
            map[i].whose=0;
            map[i].level=-1;
            updateMapNode(i);
        }
    }
}

int getGift(Player*player)
{
    char buff[3];
    scanf("%s",buff);
    buff[strcspn(buff, "\n")]='\0';
    if(strcmp(buff,"1")==0)
    {
        printf("选择奖金,获得奖金2000元\n");
        player->fund+=2000;
    }
    else if(strcmp(buff,"2")==0)
    {
        printf("选择点数卡,获得点数200点\n");
        player->points+=200;
    }
    else if(strcmp(buff,"3")==0)
    {
        printf("选择财神buff,获得buff5轮");
        player->buff+=5;
    }
    else{
        printf("您错失了机会\n");
    }
    getchar();
}