//2022/07/04 15:34
//2022/07/04 15:37 AC.
#include <stdio.h>
int main(void){
    char S;
    int ans[10] = {0};
    for (int i = 0; i < 9; i++) {
        scanf(" %c", &S);
        ans[S - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (!ans[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}