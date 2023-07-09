#include"tool.h"
#include"map.h"
extern mapnode map[MAX_MAP_NUM];
int buyTool(Player* player)
{
    char ch=' ';
    char input[100];
    //fgets(input, sizeof(input), stdin);
    printf("欢迎来到道具屋，请选择你需要的道具:\n");
    printf("1，路障；2.机器娃娃\n");
    while (ch!='F'&&ch!='f')
    {
        /*可以购买多个的代码*/
        /*点数不足*/
        if(player->points<30)
        {
            printf("点数不足，退出道具房\n");
            return 0;
        }
        /*退出*/
        else if(ch=='F'||ch=='f') break;
        /*购买单件*/
        else 
        {   
            scanf("%c", &ch);
            char input[100];
            fgets(input, sizeof(input), stdin);

            buy_one_tool(player,ch);
        }
    }
    printf("退出道具房\n");
    return 0;
}

void buy_one_tool(Player*player,char ch)
{
    if(player->toolnum[0]>=10) 
    {
        printf("道具已满\n");
        return ;
    }
    if(ch=='1')
    {
        if(player->points>=50) buyBlock(player);
        else printf("点数不足，购买失败\n");
    }
    else if(ch=='2')
    {
        if(player->points>=30) buyRobot(player);
        else printf("点数不足，购买失败\n");
    }
    else if(ch=='F'||ch=='f') return ;
    else printf("非法字符\n");
}

void buyBlock(Player*player)
{
    printf("已购买路障\n");
    player->toolnum[0]++;
    player->toolnum[1]++;
    player->points-=50;
}

void buyRobot(Player*player)
{
    printf("已购买机器娃娃\n");
    player->toolnum[0]++;
    player->toolnum[2]++;
    player->points-=30;
}

void buyBomb(Player*player)
{
    printf("已购买炸弹\n");
    player->toolnum[0]++;
    player->toolnum[3]++;
    player->points-=50;
}

int solve_Bomb(Player*player,int index)
{
    map[index].item[3]=0;//记得换成宏
    // player->loc=HOSPITAL;
    player->stop=0;
    return 0;
}
int solve_Block(Player*player,int index)
{
    map[index].item[1]=0;//记得换成宏
    // player->loc=index;
    return 1;
}