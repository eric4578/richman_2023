#include"tool.h"
#include"start.h"
#include"test.h"
#include"update.h"
#include"map.h"
#include"func.h"
#define BLOCK 1
#define ROBOT 2
#define BOMB 3
extern mapnode map[MAX_MAP_NUM];//地图
Player players[MAX_PLAYER_NUM]; //玩家
int main() {
    /*游戏初始化*/
    initMap();
    //printMap();
    start(players);
    int round=0;//游戏回合数，
    int prid=0;//记录当前玩家的id,是0到PlayerNumber-1之间的整数,初始置0
    int PlayerNumber=getPlayerNumber();//玩家数目
    int i=0,j=0;
    for(i=0;i<PlayerNumber;i++)
    {
        if(players[i].alive==1)
            map[0].user[j++]=getPlayerch(players[i].id);
    }
    updateMapNode(0);
    //buyTool(player);

    /*接受指令的变量*/
    char command[100];
    char action[20];
    char arg1[20];
    char arg2[20];
    char arg3[20];
    char arg4[20];
    getchar();

    while (1) {
        /*回合数更新*/
        if(prid==0) round+=1;
        if(players[prid].alive!=1){//死亡跳过
            prid=(prid+1)%PlayerNumber;
            continue;
        }

        /*打印地图*/
        printMap();

        /*指令输入*/
        printf("输入用户命令\n");
        
        // 从标准输入读取指令
        fgets(command, sizeof(command), stdin);  
        // 去除指令末尾的换行符
        command[strcspn(command, "\n")] = '\0';
        // 解析指令和参数
        sscanf(command, "%s %s %s %s %s", action, arg1,arg2,arg3,arg4);

        /* 根据解析的指令和参数执行相应的操作*/
        /*测试用指令*/
        //TIPs:  可以下面的set指令可以更换函数名字,我这里只是写了一个大概
        if (strcmp(action, "set") == 0) //set指令
        {
            if(strcmp(arg1,"money")==0)
            {
                setMoney(arg2,arg3);
            }
            else if(strcmp(arg1,"point")==0)
            {
                setPoint(arg2,arg3);
            }
            else if(strcmp(arg1,"item")==0)
            {
                setItem(arg2,arg3,arg4);
            }
            else if(strcmp(arg1,"buff")==0)
            {
                setBuff(arg2,arg3);
            }
            else if(strcmp(arg1,"map")==0)
            {
                setMap(arg2,arg3,arg4);
            }
            else if(strcmp(arg1,"unmap")==0)
            {
                setUnmap(arg2);
            }
            else if(strcmp(arg1,"bomb")==0)
            {
                setBomb(players,arg2);
            }
            else if(strcmp(arg1,"barrier")==0)
            {
                setBarrier(players,arg2);
            }
            else if(strcmp(arg1,"pos")==0)
            {
                setPos(arg2,arg3);
            }
            else if(strcmp(arg1,"quit")==0)
            {
                setQuit(arg2);
            }
            else if(strcmp(arg1,"stop")==0)
            {
                setStop(arg2,arg3);
            }
            else
            {
                printf("Warning:no such commond\n");
            }
        } 
        else if (strcmp(action, "step") == 0) {//step指令
            step((players+prid),atoi(arg1));
            prid=(prid+1)%MAX_PLAYER_NUM;
            //清空缓冲区
            char input[20];
            fgets(input, sizeof(input), stdin);  
            continue;
        }

        /*游戏指令*/
        else if (strcmp(action, "roll") == 0) 
        {
            int rollNumber=get_roll_number();
            step((players+prid),rollNumber);
            prid=(prid+1)%PlayerNumber;
            //清空缓冲区
            char input[20];
            fgets(input, sizeof(input), stdin);  
            continue;
        } 
        else if(strcmp(action, "sell") == 0)
        {
            sellLand(players+prid, atoi(arg1));
        }
        else if (strcmp(action, "block") == 0)
        {
            int num=atoi(arg1);
            if(players[prid].toolnum[BLOCK]>0)
            {
                putBlock((players+prid),num);//设置障碍，前后10步并放在不是玩家的位置上
            }
            else
            {
                printf("no block\n");
            }
        }
        else if (strcmp(action, "robot") == 0)
        {
            if(players[prid].toolnum[ROBOT]>0)
            {
                robotClear(players+prid);//设置障碍，前后10步并放在不是玩家的位置上
            }
            else
            {
                printf("no robot\n");
            }
        }
        else if (strcmp(action, "block") == 0)
        {
            int num=atoi(arg1);
            if(players[prid].toolnum[BOMB]>0)
            {
                putBomb(players+prid,num);//设置障碍，前后10步并放在不是玩家的位置上
            }
            else
            {
                printf("no bomb\n");
            }
        }
        else 
        {
            printf("未知指令，请重新输入\n");
        }
    }
    return 0;
    
}