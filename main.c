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
int prid;
int BuffLoc;
int BuffStay;
int BuffFlushRound;
int round;
int alivenum;

int main(int argc,char*argv[]) {

    BuffFlushRound = BUFF_START;
    BuffFlushRound = get_buff_round();
    /*游戏初始化*/
    initMap();
    //printMap();
    start(players);
    round=0;//游戏回合数，
    prid=0;//记录当前玩家的id,是0到PlayerNumber-1之间的整数,初始置0
    BuffLoc=BUFF_START;
    int buff_round=0;
    int PlayerNumber=getPlayerNumber();//玩家数目
    alivenum = PlayerNumber;
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

    while (1) {
        /*回合数更新*/
        if(players[prid].alive!=1){//死亡跳过
            prid=(prid+1)%PlayerNumber;
            continue;
        }
        

        /*打印地图*/
        printMap();
        action[0]='\0';
        /*指令输入*/
        printUser(players+prid);
        // printf("输入用户命令\n");
        
        fflush(stdin);
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
                setBomb(arg2);
            }
            else if(strcmp(arg1,"barrier")==0)
            {
                setBarrier(arg2);
            }
            else if(strcmp(arg1,"pos")==0)
            {
                setPos(arg2,arg3);
            }
            else if(strcmp(arg1,"stop")==0)
            {
                setStop(arg2,arg3);
            }
            else if(strcmp(arg1,"round")==0)
            {
                round=9;
            }
            else if(strcmp(arg1,"god")==0)
            {
                setGod(atoi(arg2));
            }
            else
            {
                printf("Warning:no such commond\n");
            }
        } 
        else if (strcmp(action, "step") == 0) {//step指令
            step((players+prid),atoi(arg1));
            if((players+prid)->buff>0)
            {
                (players+prid)->buff-=1;
                printUser((players+prid));
                printf("剩余buff:%d\n", (players+prid)->buff);
                if((players+prid)->buff==0)
                {
                    BuffLoc=BUFF_CATCH;
                }
            }
            prid=(prid+1)%PlayerNumber;
            if(prid==0) {
                
                round += 1;
                //BuffFlushRound -= 1;

                //刷新逻辑

                //起始刷新逻辑
                if(BuffLoc == BUFF_START)
                {
                    if (round == 10+BuffFlushRound) //刷新第十个回合的财神buff
                    {
                        BuffLoc=randomBuffLoc();
                        printf("财神降临到了%d的位置\n",BuffLoc);
                        updateMapNode(BuffLoc);
                        BuffStay = 5;
                    }
                }
                if (BuffLoc >= 0||BuffLoc==BUFF_CATCH)
                {
                    int flag=0;
                    BuffStay--;
                    //Buff消失，重新生成
                    if (BuffStay == 0) {//等待刷新
                        int oldbuffloc=BuffLoc;
                        if(BuffLoc==BUFF_CATCH) flag=1;
                        BuffLoc = BUFF_FLUSH; //BUFF等待刷新
                        BuffFlushRound = get_buff_round();
                        if(!flag)
                            updateMapNode(oldbuffloc);//buff消失
                        round=0;
                    }
                }
                if(round==BuffFlushRound&&BuffLoc == BUFF_FLUSH)//开始刷新
                {
                    BuffLoc = randomBuffLoc();
                    printf("财神降临到了%d的位置\n",BuffLoc);
                    updateMapNode(BuffLoc);
                    BuffStay = 5;
                }
                
            }
            /*更新角色状态*/
            // while(players[prid].stop>0){
            //     updatePlayer(players+prid);
            //     prid=(prid+1)%PlayerNumber;
            //     continue;
            // }
            //updatePlayer(players+prid);//进行buff，stop的更新
                continue;
        }

        /*游戏指令*/
        else if (strcmp(action, "roll") == 0) 
        {
            int rollNumber=get_roll_number();
            printf("你掷得的点数为%d\n", rollNumber);
            step((players+prid),rollNumber);
            if((players+prid)->buff>0)
            {
                (players+prid)->buff-=1;
                printUser((players+prid));
                printf("剩余buff:%d\n", (players+prid)->buff);
            }
            prid=(prid+1)%PlayerNumber;
            if(prid==0) {
                
                round += 1;
                //BuffFlushRound -= 1;

                //刷新逻辑

                //起始刷新逻辑
                if(BuffLoc == BUFF_START)
                {
                    if (round == 10+BuffFlushRound) //刷新第十个回合的财神buff
                    {
                        BuffLoc=randomBuffLoc();
                        printf("财神降临到了%d的位置\n",BuffLoc);
                        updateMapNode(BuffLoc);
                        BuffStay = 5;
                    }
                }
                if (BuffLoc >= 0||BuffLoc==BUFF_CATCH)
                {
                    int flag=0;
                    BuffStay--;
                    //Buff消失，重新生成
                    if (BuffStay == 0) {//等待刷新
                        int oldbuffloc=BuffLoc;
                        if(BuffLoc==BUFF_CATCH) flag=1;
                        BuffLoc = BUFF_FLUSH; //BUFF等待刷新
                        BuffFlushRound = get_buff_round();
                        if(!flag)
                            updateMapNode(oldbuffloc);//buff消失
                        round=0;
                    }
                }
                if(round==BuffFlushRound&&BuffLoc == BUFF_FLUSH)//开始刷新
                {
                    BuffLoc = randomBuffLoc();
                    printf("财神降临到了%d的位置\n",BuffLoc);
                    updateMapNode(BuffLoc);
                    BuffStay = 5;
                }
                
            }
            
            /*更新角色状态*/
            // if(players[prid].stop>0){
            //     updatePlayer(players+prid);
            //     prid=(prid+1)%PlayerNumber;
            //     continue;
            // }
            //updatePlayer(players+prid);//进行buff，stop的更新
            //清空缓冲区
            // char input[20];
            // fgets(input, sizeof(input), stdin);  
            continue;
        } 
        else if(strcmp(action, "sell") == 0)
        {
            sellLand(players+prid, atoi(arg1));
            updateMapNode(atoi(arg1));
            
        }
        else if (strcmp(action, "block") == 0)
        {
            block(players+prid, atoi(arg1));
            updateMapNode((players + prid)->loc + atoi(arg1));
        }
        else if (strcmp(action, "robot") == 0)
        {
            robot(players + prid);
        }
        // else if (strcmp(action, "bomb") == 0)
        // {
        //     bomb(players+prid, atoi(arg1));
        // }
        else if(strcmp(action, "query") == 0)
        {
            // printf("总财产%d\n",query(players+prid));
            query(players + prid);
        }
        else if (strcmp(action, "dump") == 0)
        {
            if(argc>=2)
                dump_file(players, PlayerNumber, prid, argv[1]);
            else 
                dump_file(players, PlayerNumber, prid, "./dump.out");
        }
        else if(strcmp(action, "quit") == 0)
        {
            quit();
            break;
        }
        else if(strcmp(action, "help") == 0)
        {
            help();
            break;
        }
        else 
        {
            printf("未知指令，请重新输入\n");
        }
    }
    return 0;
    
}