//#include"map.h"

// int printMap()
// {

// }
#include <stdio.h>
#include"map.h"
#include"Player.h"
mapnode map[MAX_MAP_NUM];
int initMap()
{
    int price=200;
    for(int i=0;i<70;i++)
    {
        map[i].ch='0';
        for(int j=0;j<4;j++)
            map[i].user[j]=0;
        for(int j=0;j<3;j++)
            map[i].item[j]=0;
        map[i].loc_id=i;
        map[i].whose=0;
        map[i].level=0;
        map[i].color=0;
        if(i==29) price=500;
        else if(i==35) price=300;
        map[i].price=price;
    }
    map[HOSPITAL].ch='H';
    map[HOSPITAL].price=-1;
    map[TOOLROOM].ch='T';
    map[TOOLROOM].price=-1;
    map[GIFTROOM].ch='G';
    map[GIFTROOM].price=-1;
    map[PRISON].ch='P';
    map[PRISON].price=-1;
    map[MAGICROOM].ch='M';
    map[MAGICROOM].price=-1;
    map[0].ch='S';
    for(int i=MAGICROOM+1;i<MAX_MAP_NUM;i++)
    {
        map[i].ch='$';
        map[i].price=-1;
    }
}

int printNode(mapnode node)//根据打印的地点打印单个字符
{
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
    else if(index==HOSPITAL)
        map[index].ch='H';
    else if(index==PRISON)
        map[index].ch='P';
    else if(index==TOOLROOM)
        map[index].ch='T';
    else if(index==GIFTROOM)
        map[index].ch='G';
    else if(index==MAGICROOM)
        map[index].ch='M';
    else if(index>MAGICROOM)
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
    if(map[index].item[0])
    {
        map[index].ch='#';
    }
    if(map[index].item[2])
    {
        map[index].ch='@';
    }
    //有没有玩家，最后的玩家显示
    if(map[index].user[0])
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

