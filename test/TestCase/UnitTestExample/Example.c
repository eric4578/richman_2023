#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    FILE* f;
    if(argc == 1){
        f = fopen("./dump.out", "w+");
    }else{
        f = fopen(argv[1], "w+");
    }

    if (f != NULL){
        char str[10] = {};
        sprintf(str, "%d %d %d\n", a, b, c);
        fputs(str, f);
        fclose(f);
    } 

    return 0;
}