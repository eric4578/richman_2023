/*test包含测试函数，即set指令以及dump输出指令*/
#include"test.h"
#include "map.h"
#include<string.h>
extern mapnode map[MAX_MAP_NUM];
extern Player players[MAX_PLAYER_NUM];
extern int BuffLoc;
extern int BuffStay;
static char NameToIndex[MAX_PLAYER_NUM + 1][10] = { // 玩家id和玩家名字的映射关系，1234分别和用户建立角色时的1234相同
        "",
        "Q",
        "A",
        "S",
        "J",
};

int _searchIndex(char* name){
    int i = 0;
    for (i = 0; i < MAX_PLAYER_NUM; i++){
        if((*name) == getPlayerch(players[i].id))
            return i;
        else 
        {
            continue;
        }
    }
    
    return -1;
}


int searchIndex(char*name){
    int i=0;
    for (i=0;i<MAX_PLAYER_NUM;i++){
        if(name[0]==getPlayerch(players[i].id))
            return i;
        else 
        {
            continue;
        }
    }
    
    return -1;
}

int searchIndexfromId(int id)
{
    for(int i=0;i<MAX_PLAYER_NUM;i++)
    {
        if(players[i].id==id)
        {
            return i;
        }
    }
    return 0;
}

void setMoney(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].fund = atoi(arg3);
}
void setPoint(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].points = atoi(arg3);
}
void setItem(char*arg2,char*arg3,char*arg4)
{
    int index = searchIndex(arg2);
    int num = atoi(arg4);
    players[index].toolnum[0]+=num;
    players[index].toolnum[atoi(arg3)] += num;
}
void setBuff(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].buff = atoi(arg3);
}
void setMap(char*arg2,char*arg3,char*arg4)
{   
    if(atoi(arg2) >= 70) {
        printf("位置超出限制");
        return ;
    }
    if(atoi(arg4) > 3) {
        printf("等级设置错误\n");
        return ;
    }
    
    int index = searchIndex(arg3);
    map[atoi(arg2)].whose = players[index].id;
    map[atoi(arg2)].level = atoi(arg4);
    players[index].house[atoi(arg2)] = atoi(arg4);
}
void setUnmap(char*arg2)
{
    int index = searchIndexfromId(map[atoi(arg2)].whose);
    players[index].house[atoi(arg2)] = -1;
    map[atoi(arg2)].whose = 0;
    map[atoi(arg2)].level = 0;
}
void setBomb(char*arg2)
{
    map[atoi(arg2)].item[3] = 1;
}
void setBarrier(char*arg2)
{
    map[atoi(arg2)].item[1] = 1;
}
void setPos(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    int nowPos = players[index].loc;

    char ch = arg2[0];

    for (int i=0;i<MAX_PLAYER_NUM;i++)
        if (map[nowPos].user[i] == ch ){
            for (int j=i;j<MAX_PLAYER_NUM;j++)
                map[nowPos].user[j]=map[nowPos].user[j+1];
            break;
        }
    int pos = atoi(arg3);
    players[index].loc = pos;
    char* tmp = arg3;
    for(int i=MAX_PLAYER_NUM;i>0;i--)
    {
        map[pos].user[i]=map[pos].user[i-1];
    }
    map[pos].user[0]=arg2[0];
    
}
void setStop(char*arg2,char*arg3)
{
    int index = searchIndex(arg2);
    players[index].stop = atoi(arg3);
}

void setGod(int loc)
{
    BuffLoc=loc;
    updateMapNode(BuffLoc);
    printf("财神降临在%d的位置\n",BuffLoc);
    BuffStay=5;
}
/*
    function:dump one player's related info into the file
    parameter : player info to be added
    return value : 1: error occured, 0:successfully performed
*/
int Dump_One_Player(FILE* fp, Player *p, int PlayerNumber, char*file_path){

    char P_Order[6] = "!QASJ";

    for(int i = 0; i < MAX_PLAYER_NUM; ++i) {
        int index=0;

        if(searchIndex(P_Order + i + 1) == -1) //玩家死亡或者位初始化
        {
            index=searchIndex(P_Order+i+1);
            fprintf(fp, "%c\n",P_Order[i+1]);
            char line[50];
            sprintf(line, "alive %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "money %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "point %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "item1 %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "item2 %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "item3 %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "buff %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "stop %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "userloc %d", (p+index)->loc);
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
                
        }
        else{
            index=searchIndex(P_Order+i+1);
            fprintf(fp, "%c\n",P_Order[i+1]);
            char line[50];
            int index=searchIndexfromId(i+1);
            sprintf(line, "alive %d",(p+index)->alive );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "money %d",(p+index)->fund );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "point %d",(p+index)->points );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
            sprintf(line, "item1 %d",(p+index)->toolnum[1] );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "item2 %d",(p+index)->toolnum[2] );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "item3 %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "buff %d",(p+index)->buff );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "stop %d",0 );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));

            sprintf(line, "userloc %d",(p+index)->loc );
            fprintf(fp, "%s\n",line);
            memset(line,0,sizeof(line));
        }
    }
    return 1;
}

/*

*/
// int Dump_Line(FILE* fp, char * line,int line_num,char*file_path){
//     //char file_path[20] = "../dump.txt";

//     return 0;
// }

int Dump_line_overload();

int dump_file(Player* p, int PlayerNumber, int preuser, char*file_path){
    FILE* fp = fopen(file_path,"w");
    printf("file_path:%s\n", file_path);

    // file_path == "./dump.put"
    // fprintf(fp, "file_path %s", file_path);
    
    if (!fp)
    {
        printf("error occured during an attempt to open %s\n", file_path);
        return 1;//failed
    }

	char line[50];//single line of dump.txt file
    char P_Order[6] = " QASJ";//for test use

    sprintf(line,"user ");
    fprintf(fp, "%s",line);
    memset(line,0,sizeof(line));
    for(int i = 0; i < PlayerNumber; ++i)
    {
        sprintf(line,"%c", P_Order[(p+i)->id]);
        fprintf(fp, "%s",line);
        memset(line,0,sizeof(line));
    }
    fprintf(fp, "%s\n",line);
    memset(line,0,sizeof(line));

    printf("%d\n", preuser);

    sprintf(line,"preuser %c",P_Order[p[preuser].id ]);
    fprintf(fp, "%s\n",line);
    memset(line,0,sizeof(line));

    Dump_One_Player(fp, p, PlayerNumber, file_path);

    fprintf(fp, "MAP\n");

    for (int i = 0; i < 70; ++i)
    {   
        if(strlen(map[i].user) != 0 &&map[i].user[0]!='0')
        {
            char buf[MAX_PLAYER_NUM+1];
            int index=0;
            for(int j=MAX_PLAYER_NUM;j>=0;j--){
                if (map[i].user[j]=='Q'||
                    map[i].user[j]=='A'||
                    map[i].user[j]=='S'||
                    map[i].user[j]=='J')
                    {
                        buf[index]=map[i].user[j];
                        index++;
                    }
            }
            for(int k=1;k<MAX_PLAYER_NUM;k++)
            {
                if(map[i].user[k]=='0')
                map[i].user[k]='\0';
            }
            buf[index]='\0';
            if(i==0) sprintf(line,"mapuser %d %s",i,map[i].user);
            else sprintf(line,"mapuser %d %s",i,buf);
            fprintf(fp, "%s\n",line);
        }
    }
    for (int i = 0; i < 70; ++i)
    {
        if(map[i].whose != 0)
        {
            sprintf(line,"map %d %c %d",i,P_Order[map[i].whose],map[i].level);
            fprintf(fp, "%s\n",line);
        }
        
    }
    for (int i = 0; i < 70; ++i)
    {
        if(map[i].item[1]== 0 && map[i].item[3] == 0) continue;
        int item_t = map[i].item[1] == 1 ? 1:3;
        sprintf(line,"item %d %d",i,item_t);
        fprintf(fp, "%s\n",line);
    }
    fclose(fp);
    return 0;

}
