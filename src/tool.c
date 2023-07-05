#include"tool.h"

int buyTool(Player* player)
{
    char ch=' ';
<<<<<<< HEAD
    int i=0;//一次性测试用
    //printf("欢迎来到道具屋，请选择你需要的道具:");
    while (ch!='F'&&ch!='f')
    {
        /*假设一次只能购买一个道具的代码*/
        if(i<1)
        {
        scanf("%c", &ch);
        scanf("%d", &(player->points));
        scanf("%d", &(player->toolnum[0]));
        //为了防误触
        char input[100];
        fgets(input, sizeof(input), stdin);
        }

        /*可以购买多个的代码*/
        // scanf("%c", &ch);
        // scanf("%d", &(player->points));
        // scanf("%d", &(player->toolnum[0]));
        // char input[100];
        // fgets(input, sizeof(input), stdin);
        // i=0;

=======
    //printf("欢迎来到道具屋，请选择你需要的道具:");
    while (ch!='F'&&ch!='f')
    {
        /*可以购买多个的代码*/
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
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
<<<<<<< HEAD
        {   if(i>=1) return 0;
            buy_one_tool(player,ch);
        }
        i++;
=======
        {   
            scanf("%c", &ch);
            char input[100];
            fgets(input, sizeof(input), stdin);

            buy_one_tool(player,ch);
        }
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
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
    else if(ch=='3')
    {
        if(player->points>=50) buyBomb(player);
        else printf("点数不足，购买失败\n");
    }
    else if(ch=='F'||ch=='f') return ;
    else printf("非法字符\n");
}

void buyBlock(Player*player)
{
    printf("已购买路障\n");
    player->toolnum[1]++;
    player->points-=50;
}

void buyRobot(Player*player)
{
    printf("已购买机器娃娃\n");
    player->toolnum[2]++;
    player->points-=30;
}

void buyBomb(Player*player)
{
    printf("已购买炸弹\n");
    player->toolnum[3]++;
    player->points-=50;
}