//2022/07/17 21:00
//
#include <stdio.h>
int main(void){
    char S[4];
    scanf("%s", S);
    int flag2 = 1;
    for (int i = 0; i < 3; i++) {
        int flag1 = 1;
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                continue;
            }
            if (S[i] == S[j]) {
                flag1 = 0;
                break;
            }
        }
        if (flag1) {
            printf("%c\n", S[i]);
            flag2 = 0;
            break;
        }
    }
    if (flag2) {
        puts("-1");
    }
    return 0;
}