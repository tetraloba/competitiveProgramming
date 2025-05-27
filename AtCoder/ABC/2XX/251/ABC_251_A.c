//2022/07/03 15:24 AC.
#include <stdio.h>
int main(void){
    char S[4];
    scanf("%s", S);
    int count = 0;
    while (S[count]) {
        count++;
    }
    for (int i = 0; i < 6 / count; i++) {
        printf("%s", S);
    }
    putchar('\n');
    return 0;
}