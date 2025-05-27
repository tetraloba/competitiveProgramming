//2022/07/06 17:05
//2022/07/06 17:10 AC.
#include <stdio.h>
int main(void){
    char S[5];
    scanf("%s", S);
    for (int i = 3; i > 0; i--) {
        S[i] = S[i - 1];
    }
    S[0] = '0';
    printf("%s\n", S);
    return 0;
}