#include <stdio.h>
int main(void){
    char c;

    printf("文字を入力してください: ");
    scanf("%c", &c);

    printf("入力した文字は %c です。\n", c);

    return 0;
}