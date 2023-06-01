#include <stdio.h>
int main(void){
    int num;    //枚数
    char suit;  //絵柄

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%c", &suit);
        printf("i の値は %d です。\n", i);
        printf("num の値は %d です。\n", num);
        printf("suit の値は %c です。\n", suit);
    }

    return 0;
}