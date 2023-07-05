#include "start.h"
<<<<<<< HEAD

/*游戏一开始最先调用的函数*/
Player* start()
{
    char s[5] = "\0";
    int fund = get_set_fund();
    Player *player = NULL;
    while (player == NULL)
    {   
        //printf("请输入角色：\n");
        scanf("%s", s);
        player = set_init_role(s);
    }
    set_init_fund(player,fund);
    return player;
=======
#include"global.h"
/*游戏一开始最先调用的函数*/
int start(Player*players)
{
    char s[5] = "\0";
    int flag=-1;
    int fund = get_set_fund();
    printf("请输入角色：\n");
    while(flag==-1){//输入错误会让重输
        scanf("%s", s);
        flag=set_init_role(players,s);
    }
    set_init_fund(players,fund);
    
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
}

/*设置初始资金*/
void set_init_fund(Player *player, int fund)
{
<<<<<<< HEAD
    int id=player->id;
    do{
        player->fund=fund;
        player=player->next;
    }while (player->id!=id);
}

/*设置初始角色，传入一组数字字符,返回角色指针*/
Player *set_init_role(char *s)
=======
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
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
{
    // isdigital
    char *c = s;
    while ((*c) != '\0')
    {
        if (!isdigit(*c))
        {
            printf("非法输入\n");
<<<<<<< HEAD
            return NULL;
=======
            return -1;
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
        }
        c++;
    }
    // num is not in [2,4]
    int num = strlen(s);
    if (num < 2 || num > 4)
    {
        printf("玩家必须要2-4人\n");
<<<<<<< HEAD
        return NULL;
    }
    // 设置role,构建循环链表
    else
    {
        PlayerNumber=num;
        Player *player = (Player *)malloc(sizeof(Player));
        player->next = player;
        initPlayer(player, (*s) - '0');
        Player *p = player, *q = NULL;
        for (int i = 0; i < num - 1; i++)
        {
            q = (Player *)malloc(sizeof(Player));
            q->next = p->next;
            p->next = q;
            p=q;
            initPlayer(q, *(++s) - '0');
            
        }
        return player;
    }
=======
        return -1;
    }
    else{
        PlayerNumber=num;
        for(int i=0;i<MAX_PLAYER_NUM;i++)
        {
            int id=*(s)-'0';
            if(id-1!=i) {(players+i)->alive=0;}
            else {initPlayer((players+i),id);s++;}
        }
        return 0;
    }
    // 设置role,构建循环链表
    // else
    // {
    //     PlayerNumber=num;
    //     Player *player = (Player *)malloc(sizeof(Player));
    //     player->next = player;
    //     initPlayer(player, (*s) - '0');
    //     Player *p = player, *q = NULL;
    //     for (int i = 0; i < num - 1; i++)
    //     {
    //         q = (Player *)malloc(sizeof(Player));
    //         q->next = p->next;
    //         p->next = q;
    //         p=q;
    //         initPlayer(q, *(++s) - '0');
            
    //     }
    //     return player;
    // }
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
}

/*初始化player参数的函数，为了以后方便添加做的*/
void initPlayer(Player *player, int id)
{
    player->id = id;
    player->points = 0;
    player->fund=0;
<<<<<<< HEAD
=======
    player->buff=0;
    player->alive=1;
    player->stop=0;
    player->loc=0;
    for(int i=0;i<MAX_MAP_NUM;i++)
        player->house[i]=-1;
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
    for (int i = 0; i < 4; i++)
        player->toolnum[i] = 0;
}

/*为了实现默认和输错重输的功能，返回输入的资金数或者默认值10k*/
int get_set_fund()
{
    int num = 10000; // 默认值

    while (1)
    {
<<<<<<< HEAD
        //printf("设置初始资金");
=======
        printf("设置初始资金");
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
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
<<<<<<< HEAD
    return 0;
}

/*释放player*/
void freePlayer(Player*p)
{
    Player *q=p->next;
    for(int i=0;i<PlayerNumber;i++)
    {
        q=p->next;
        free(p);
        p=q;
    }
=======
    return num;
}

int getPlayerNumber()
{
    return PlayerNumber;//返回静态变量
>>>>>>> aed0620babbca38c9c04f0cdceb275b2ae2fab08
}
