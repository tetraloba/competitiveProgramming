//2022/06/05  7:43
//2022/06/05  7:49 AC
#include <stdio.h>
int main(void){
    char S[11], T[11];
    scanf("%s %s", S, T);
    for (int i = 0; i < 11; i++) {
        if (S[i] < T[i]) {
            printf("Yes\n");
            break;
        } else if (T[i] < S[i]) {
            printf("No\n");
            break;
        }
        if (S[i + 1] == 0) {
            printf("Yes\n");
            break;
        }
        if (T[i + 1] == 0) {
            printf("No\n");
            break;
        }
    }
    return 0;
}