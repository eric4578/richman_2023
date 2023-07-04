//#include"map.h"

// int printMap()
// {

// }
#include <stdio.h>
#include"map.h"

int initMap()
{
    for(int i=0;i<70;i++)
    {
        map[i].ch='o';
        for(int j=0;j<4;j++)
            map[i].user[j]=0;
        for(int j=0;j<3;j++)
            map[i].item[j]=0;
        map[i].loc_id=i;
        map[i].whom=0;
        map[i].level=0;
    }
}

int printNode(mapnode node)
{
    
    //TODO
}

int printMap(int width, int height) //未完善
{
    int left = 0;
    int right = width - 1;
    int top = 0;
    int bottom = height - 1;

    while (left <= right && top <= bottom) {
        // 打印上边界
        for (int i = left; i <= right; i++) {
            printf("*");
        }
        top++;

        // 打印右边界
        for (int i = top; i <= bottom; i++) {
            printf("\n");
            for (int j = left; j <= right; j++) {
                if (j == right) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        right--;

        // 打印下边界
        if (top <= bottom) {
            printf("\n");
            for (int i = right; i >= left; i--) {
                printf("*");
            }
            bottom--;
        }

        // 打印左边界
        if (left <= right) {
            printf("\n");
            for (int i = bottom; i >= top; i--) {
                printf("*");
            }
            left++;
        }
    }
}




// int main() {
    

//     return 0;
// }