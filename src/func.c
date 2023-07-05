#include"func.h"
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
        printf("此地已经被别人购买\n");
        return ERROR;
    }
    // 用户的可用资产不足以购买当前土地
    if(player->fund < map[index].price) {
        printf("你的资金不足以购买或升级当前土地\n");
        return ERROR;
    }
    else {
        // 当前地块属于当前的玩家，玩家可以选择升级
        if(map[index].whose == player->id) {
            //当前土地的等级已经最高，玩家不能再升级
            if(map[index].level >= LEVEL3) {
                printf("当前土地已经处于最高等级，不能购买或升级\n");
                return ERROR;
            }
            //玩家可以选择升级当前土地
            else {
                printf("你是否选择升级这块土地(y/n)\n");
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
            printf("你是否选择购买这块土地(y/n)\n");
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
        printf("这块地产不属于你，你无法进行售卖\n");
        return ERROR;
    }
    else {
        //玩家出售地块，玩家资产更新，拥有地块更新，地块属性更新
        player->fund += map[index].price * (map[index].level + 1);
        //todo: 等待最后确认house初始化内容
        player->house[index] = -1;
        map[index].whose = 0;
        map[index].level = 0;
    }
    return OK;
}