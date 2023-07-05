#include"tool.h"
int main(){
    int a, b, c;
    scanf("%d", &a);
    printf("%d\n", a);
    scanf("%d", &b);
    printf("%d\n", b);
    scanf("%d", &c);
    printf("%d\n", c);
    Player *player;
    player->points=b;
    player->toolnum[0]=c;
    buy_one_tool(player,a);
    return 0;
}