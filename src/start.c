#include "start.h"
#include"global.h"
/*游戏一开始最先调用的函数*/
int start(Player*players)
{
    char s[256] = "\0";
    int flag=-1;
    char c;
    int fund = get_set_fund();
    
    while(flag==-1){//输入错误会让重输    
        printf("请输入角色(1：钱夫人，2：阿土伯，3：孙小美，4：金贝贝):");
        fgets(s, sizeof(s), stdin);
        // 检查输入是否超出长度限制
        s[strcspn(s, "\n")] = '\0';
        if (strlen(s) > 4) {
            printf("输入错误！请重新输入\n");
            memset(s, 0, sizeof(s));
            fflush(stdin);
            continue;
        }
        flag=set_init_role(players,s);
    }
    set_init_fund(players,fund);
}

/*设置初始资金*/
void set_init_fund(Player *player, int fund)
{
    for(int i=0;i<MAX_PLAYER_NUM;i++)
    {
        if(player[i].alive==1)
        {
            (player+i)->fund=fund;
        }
    }
}

/*设置初始角色，传入一组数字字符,返回角色指针*/
int set_init_role(Player*players,char*s)
{
    // isdigital
    char *c = s;
    while ((*c) != '\0')
    {
        if (!isdigit(*c) || (*c - '0') <= 0 || (*c - '0') > 4)
        {
            printf("非法输入\n");
            return -1;
        }
        c++;
    }
    if(!isUniqueChars(s)) 
    {
        printf("非法输入\n");
        return -1;
    }
    // num is not in [2,4]
    int num = strlen(s);
    if (num < 2 || num > 4)
    {
        printf("玩家必须要2-4人\n");
        return -1;
    }
    else{
        PlayerNumber=num;
        for(int i=0;i<PlayerNumber;i++)
        {
            int id=*(s+i)-'0';
            // if(id-1!=i) {(players+i)->alive=0;}
            // else {initPlayer((players+i),id);s++;}
            initPlayer(players+i,id);
        }
        return 0;
    }
}

/*判断各不相同*/
int isUniqueChars(char *str) {
    int length = strlen(str);
    
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                return 0; // 如果有相同的字符，返回0表示不唯一
            }
        }
    }
    
    return 1; // 如果没有相同的字符，返回1表示唯一
}

/*初始化player参数的函数，为了以后方便添加做的*/
void initPlayer(Player *player, int id)
{
    player->id = id;
    player->points = 0;
    player->fund=0;
    player->buff=0;
    player->alive=1;
    player->stop=0;
    player->loc=0;
    for(int i=0;i<MAX_MAP_NUM;i++)
        player->house[i]=-1;
    for (int i = 0; i < 4; i++)
        player->toolnum[i] = 0;
}

/*为了实现默认和输错重输的功能，返回输入的资金数或者默认值10k*/
int get_set_fund()
{
    int num = 10000; // 默认值

    while (1)
    {
        printf("设置初始资金(1000-50000，回车默认10000)：");
        fflush(stdout);

        char input[100];
        fgets(input, sizeof(input), stdin);

        // 去除输入字符串中的换行符
        input[strcspn(input, "\n")] = '\0';

        if (input[0] == '\0')
        {
            // 输入为空行，保持默认值
            break;
        }

        // 尝试将字符串转换为整数
        int newNum = atoi(input);

        if (newNum >= 1000 && newNum <= 50000)
        {
            // 输入符合要求，更新num的值并跳出循环
            num = newNum;
            break;
        }
        else
        {
            printf("输入不符合要求，请重新输入。\n");
        }
    }
    return num;
}

int getPlayerNumber()
{
    return PlayerNumber;//返回静态变量
}
