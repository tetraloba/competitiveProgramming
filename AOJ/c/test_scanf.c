#include <stdio.h>
int main(void){
    int num;    //枚数
    char suit;  //絵柄
    int rank;   //数字

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%c", &suit);
    }

    return 0;
}