//#include"map.h"

// int printMap()
// {

// }
#include <stdio.h>
#include"map.h"
#include"Player.h"
extern int prid;
extern Player players[MAX_PLAYER_NUM];
extern int BuffLoc;
mapnode map[MAX_MAP_NUM];
int initMap()
{
    int price=200;
    for(int i=0;i<70;i++)
    {
        map[i].ch='0';
        for(int j=0;j<4;j++)
            map[i].user[j]='\0';
        //map[i].user[0]=0;
        for(int j=0;j<3;j++)
            map[i].item[j]=0;
        map[i].loc_id=i;
        map[i].whose=0;
        map[i].level=-1;
        map[i].color=0;
        if(i==29) price=500;
        else if(i==35) price=300;
        map[i].price=price;
    }
    map[PARK1].ch='P';
    map[PARK1].price=-1;
    map[TOOLROOM].ch='T';
    map[TOOLROOM].price=-1;
    map[GIFTROOM].ch='G';
    map[GIFTROOM].price=-1;
    map[PARK2].ch='P';
    map[PARK2].price=-1;
    //map[MAGICROOM].ch='M';
    //map[MAGICROOM].price=-1;
    map[0].ch='S';
    map[0].price=-1;
    for(int i=64;i<MAX_MAP_NUM;i++)
    {
        map[i].ch='$';
        map[i].price=-1;
    }
}

int printUser(Player* player) {
    switch (player->id)
    {
    case 1:
        printf(ANSI_COLOR_RED"%s>"ANSI_COLOR_RESET, NAME_FROM_ID[player->id]);
        break;
    case 2:
        printf(ANSI_COLOR_GREEN"%s>"ANSI_COLOR_RESET, NAME_FROM_ID[player->id]);
        break;
    case 3:
        printf(ANSI_COLOR_BLUE"%s>"ANSI_COLOR_RESET, NAME_FROM_ID[player->id]);
        break;
    case 4:
        printf(ANSI_COLOR_YELLOW"%s>"ANSI_COLOR_RESET, NAME_FROM_ID[player->id]);
        break;
    default:
        break;
    }
    return 0;
}

int printNode(mapnode node)//根据打印的地点打印单个字符
{
    // if(node.loc_id==players[prid]
    switch(node.color)
    {
        case RED:
            printf(ANSI_COLOR_RED"%c"ANSI_COLOR_RESET,node.ch);
            break;
        case GREEN:
            printf(ANSI_COLOR_GREEN"%c"ANSI_COLOR_RESET,node.ch);
            break;
        case YELLOW:
            printf(ANSI_COLOR_YELLOW"%c"ANSI_COLOR_RESET,node.ch);
            break;
        case BLUE:
            printf(ANSI_COLOR_BLUE"%c"ANSI_COLOR_RESET,node.ch);
            break;
        case MAGENTA:
            printf(ANSI_COLOR_MAGENTA"%c"ANSI_COLOR_RESET,node.ch);
            break;
        case CYAN:
            printf(ANSI_COLOR_CYAN"%c"ANSI_COLOR_RESET,node.ch);
            break;
        default:
            printf("%c",node.ch);
            break;
    }
}

int printMap() //to test
{
    int length=29,width=8;
    int row=0,column=0,id=0;
    while(row<width)
    {
        while(column<length)
        {
            if(row==0)
            {
                printNode(map[column]);
                column++;
            }
            else if(row==width-1)
            {
                printNode(map[63-column]);
                column++;
            }
            else 
            {
                if(column==0)
                printNode(map[MAX_MAP_NUM-row]);
                else if(column==length-1)
                printNode(map[length-1+row]);
                else
                printf(" ");
                column++;
            }
            
        }
        column=0;
        row++;
        printf("\n");
    }
}


int updateMapNode(int index)//更新对应节点的显示字符和颜色
{
    //首先置为默认
    map[index].color=0;
    if(index==0)
        map[index].ch='S';
    else if(index==PARK1)
        map[index].ch='P';
    else if(index==PARK2)
        map[index].ch='P';
    else if(index==TOOLROOM)
        map[index].ch='T';
    else if(index==GIFTROOM)
        map[index].ch='G';
    else if(index>63)
        map[index].ch='$';
    else 
        map[index].ch='0';
    //然后有没有房产
    if(map[index].whose!=0)
    {
        map[index].ch=map[index].level+'0';
        map[index].color=getcolor(getPlayerch(map[index].whose));
    }
    //有没有道具
    if(BuffLoc==index)
    {
        map[index].ch='F';
    }
    if(map[index].item[1])
    {
        map[index].ch='#';
    }
    
    //有没有玩家，最后的玩家显示
    if(map[index].user[0]&&map[index].user[0]!='\0')
    {
        map[index].ch=map[index].user[0];
        map[index].color=getcolor(map[index].user[0]);
    }
}

/*接受玩家字母，返回对应颜色*/
int getcolor(char ch)
{
    switch (ch)
    {
    case 'Q':
        return RED;
        break;
    case 'A':
        return GREEN;
        break;
    case 'S':
        return BLUE;
        break;
    case 'J':
        return YELLOW;
        break;
    default:
        return 0;
        break;
    }
}

int get_Mine_points(int index)
{
    switch (index)
    {
    case 69:
        return 20;
        break;
    
    case 68:
        return 80;
        break;

    case 67:
        return 100;
        break;
    
    case 66:
        return 40;
        break;
    
    case 65:
        return 80;
        break;
    
    case 64:
        return 60;
        break;
    default:
        return 0;
        break;
    }
}
