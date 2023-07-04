#include"tool.h"
#include"start.h"
#include"test.h"
#include"update.h"
#include"map.h"
#define BLOCK 1
#define ROBOT 2
#define BOMB 3

int main() {
    /*游戏初始化*/
    //Player*player=start();
    int round=0;//游戏回合数
    int prid=0;//记录一个回合中玩家都进行数,是0到PlayerNumber-1之间的整数,初始置-1
    Player*player=(Player*)malloc(sizeof(Player));
    buyTool(player);
    return 0;//第一次测试s
    /*接受指令的代码*/
    char command[100];
    char action[20];
    char arg1[20];
    char arg2[20];
    char arg3[20];
    char arg4[20];

    while (1) {
        //printf("请输入指令：");
        printMap();
        fgets(command, sizeof(command), stdin);  // 从标准输入读取指令

        // 去除指令末尾的换行符
        command[strcspn(command, "\n")] = '\0';

        // 解析指令和参数
        sscanf(command, "%s %s %s %s %s", action, arg1,arg2,arg3,arg4);

        /* 根据解析的指令和参数执行相应的操作*/
        /*测试用指令*/
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
                setBomb(player,arg2);
            }
            else if(strcmp(arg1,"barrier")==0)
            {
                setBarrier(player,arg2);
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
            step(player,atoi(arg1));
            changePlayer(player);
            prid=(prid+1)%PlayerNumber;
            if(prid==0) round++;
            continue;
        }

        /*游戏指令*/
        else if (strcmp(action, "roll") == 0) 
        {
            int rollNumber=get_roll_number();
            step(player,rollNumber);
            //立即换下一个角色
            changePlayer(player);
            prid=(prid+1)%PlayerNumber;
            if(prid==0) round++;
            continue;
        } 
        else if (strcmp(action, "block") == 0)
        {
            int num=atoi(arg1);
            if(player->toolnum[BLOCK]>0)
            {
                putBlock(player,num);//设置障碍，前后10步并放在不是玩家的位置上
            }
            else
            {
                printf("no block\n");
            }
        }
        else if (strcmp(action, "robot") == 0)
        {
            if(player->toolnum[ROBOT]>0)
            {
                robotClear(player);//设置障碍，前后10步并放在不是玩家的位置上
            }
            else
            {
                printf("no robot\n");
            }
        }
        else if (strcmp(action, "block") == 0)
        {
            int num=atoi(arg1);
            if(player->toolnum[BOMB]>0)
            {
                putBomb(player,num);//设置障碍，前后10步并放在不是玩家的位置上
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
    freePlayer(player);
    return 0;
    
}