#include"func.h"
#include "Player.h"
#include "map.h"
#include "global.h"
#include<string.h>
extern mapnode map[MAX_MAP_NUM];
extern Player players[MAX_PLAYER_NUM];

/*
    function: 买入地块或者升级土地
    parameter: Player* player, int index(地块的绝对位置)
    return: OK代表购买或升级土地成功，ERROR代表无法购买或者升级土地
*/
int buyLand(Player* player, int index) {
    // 此地为特殊地点，如医院或者监狱
    // todo: 修改price设置，使用宏定义
    if(map[index].price == -1) {
        return ERROR;
    }
    // 此地已经被别人购买
    if(map[index].whose != player->id && map[index].whose != 0) {
        printf("位于%d的土地已经被%s购买\n", index, NAME_FROM_ID[map[index].whose]);
        return ERROR;
    }
    // 用户的可用资产不足以购买当前土地
    if(player->fund < map[index].price) {
        printf("你的资金不足以购买或升级位于%d的土地\n", index);
        return ERROR;
    }
    else {
        // 当前地块属于当前的玩家，玩家可以选择升级
        if(map[index].whose == player->id) {
            //当前土地的等级已经最高，玩家不能再升级
            if(map[index].level >= LEVEL3) {
                printf("位于%d的土地已经处于最高等级，不能购买或升级\n", index);
                return ERROR;
            }
            //玩家可以选择升级当前土地
            else {
                printf("你是否选择升级位于%d土地，需要花费%d(y/n)\n", index, map[index].price);
                char input[10];
                while(1) {
                    memset(input, 0, sizeof(input));
                    fgets(input, sizeof(input), stdin);
                    input[strcspn(input, "\n")] = '\0';

                    if(strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
                        player->fund -= map[index].price;
                        map[index].level++;
                        player->house[index] = map[index].level;
                        map[index].whose = player->id;
                        break;
                    }
                    else if(strcmp(input, "n") == 0 || strcmp(input, "N") == 0){
                        return ERROR;
                    }
                    else {
                        printf("输入错误，请重新输入\n");
                    }
                }
            }
        }
        //当前的地块不属于当前用户，用户可以选择购买
        else {
            printf("你是否选择购买位于%d的土地，需要花费%d(y/n)\n", index, map[index].price);
            char input[10];
            while(1) {
                memset(input, 0, sizeof(input));
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';

                if(strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
                    player->fund -= map[index].price;
                    // level变为0，代表这块地已经被购买
                    map[index].level = 0;
                    player->house[index] = map[index].level;
                    map[index].whose = player->id;
                    break;
                }
                else if(strcmp(input, "n") == 0 || strcmp(input, "N") == 0){
                    return ERROR;
                }
                else {
                    printf("输入错误，请重新输入\n");
                }
            }
        }
    }
    return OK;
}

/*
    function: 售出土地
    parameter: Player* player, int index(绝对位置)
    return: ERROR代表不可出售(用户不拥有这块地)，OK代表出售成功并更新玩家和地产信息
*/
int sellLand(Player* player, int index) {
    //玩家只能出售自己的地块，不能出售别人的地块或者没有归属的地块
    if(player->id != map[index].whose || map[index].whose == 0) {
        printf("位于%d的土地属于%s，你无法进行售卖\n", index, NAME_FROM_ID[map[index].whose]);
        return ERROR;
    }
    else {
        //玩家出售地块，玩家资产更新，拥有地块更新，地块属性更新
        printf("你出售了位于%d等级为%d的土地，你已经获得%d元\n", index, map[index].level, map[index].price * (map[index].level + 1)*2);
        player->fund += map[index].price * (map[index].level + 1)*2;
        //todo: 等待最后确认house初始化内容
        player->house[index] = -1;
        map[index].whose = 0;
        map[index].level = 0;
    }
    return OK;
}

void help(){
    printf("这里显示帮助\n");
    // TODO: 定义常量的输出字符串
}

void quit(){
    printf("退出游戏\n");
}
/*
    function: 查询玩家的所有资产
    parameter: PLAYER * player
    return:
*/ 
int query(Player * player) {
    printf("资金：%d\n", player->fund);
    printf("点数：%d\n", player->points);
    printf("地产：\n");
    printf("\t地点\t等级\t价格\n");
    for(int i = 0; i < MAX_MAP_NUM; i++) {
        if(player->house[i] >= 0) {
            printf("\t%d\t%d", i, player->house[i]);
            printf("\t%d", map[i].price);
            putchar('\n');
        }
    }
    printf("道具：\n");
    printf("\t路障: %d\n", player->toolnum[1]);
    printf("\t机器娃娃: %d\n", player->toolnum[2]);
    printf("\t炸弹: %d\n", player->toolnum[3]);
    return 0;
}

/*
    function: 玩家向前面的路上放置炸弹
    parameter: Player* player
    return: 
*/
int bomb(Player * player, int index) {
    if(player->toolnum[3] == 0) {
        printf("你并没有炸弹道具\n");
        return 0;
    }
    if(index != 0 && index <= 10 && index >= -10) {
        if((player->loc + index + 70) % 70 == HOSPITAL || (player->loc + index + 70) % 70 == PRISON) {
            printf("不能将炸弹放到医院或者监狱\n");
        }
        else if(map[(player->loc + index + 70) % 70].user[0] == 'Q' || 
                map[(player->loc + index + 70) % 70].user[0] == 'A' ||
                map[(player->loc + index + 70) % 70].user[0] == 'S' ||
                map[(player->loc + index + 70) % 70].user[0] == 'J') {
            printf("不能将炸弹放到玩家脚下\n");
        }
        //正常
        else {
            map[(player->loc + index + 70) % 70].item[3] = 1;
            player->toolnum[3]--;
            player->toolnum[0]--;
            updateMapNode((player->loc + index + 70) % 70);
        }
    }
    return 0;
}

int block(Player * player, int index) {
    if(player->toolnum[1] == 0) {
        printf("你并没有路障道具\n");
        return 0;
    }
    if(index != 0 && index <= 10 && index >= -10) {
        if((player->loc + index + 70) % 70 == HOSPITAL || (player->loc + index + 70) % 70 == PRISON) {
            printf("不能将炸弹放到医院或者监狱\n");
        }
        else if(map[(player->loc + index + 70) % 70].user[0] == 'Q' || 
                map[(player->loc + index + 70) % 70].user[0] == 'A' ||
                map[(player->loc + index + 70) % 70].user[0] == 'S' ||
                map[(player->loc + index + 70) % 70].user[0] == 'J') {
            printf("不能将炸弹放到玩家脚下\n");
        }
        //正常
        else {
            map[(player->loc + index + 70) % 70].item[1] = 1;
            player->toolnum[1]--;
            player->toolnum[0]--;
            updateMapNode((player->loc + index + 70) % 70);
        }
    }
    return 0;
}

int robot(Player * player) {
    if(player->toolnum[2] == 0) {
        printf("你并没有机器娃娃道具\n");
        return 0;
    }
    for(int i = 1; i <= 10; i++) {
        int index = (player->loc + i) % 70;
        map[index].item[1] = map[index].item[3] = 0;
        updateMapNode(index);
    }
    player->toolnum[2]--;
    player->toolnum[0]--;
    
    return 0;
}
