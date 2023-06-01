#include <stdio.h>
int main(void){
    int num;    //枚数
    char suit;  //絵柄
    int rank;   //数字

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%c", &suit);
        scanf("%d", &rank);
        if (suit == 'S') {
            printf("S %d\n", rank);
        } else if (suit == 'H') {
            printf("H %d\n", rank);
        } else if (suit == 'C') {
            printf("C %d\n", rank);
        } else {
            printf("D %d\n", rank);
        }
    }
    putchar('\n');

    return 0;
}