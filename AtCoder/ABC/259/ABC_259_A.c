//2022/07/09 21:00
//2022/07/09 21:06 AC.
#include <stdio.h>
int main(void){
    int N, M, X, T, D, ans;
    scanf("%d %d %d %d %d", &N, &M, &X, &T, &D);
    if (X < M) {
        ans = T;
    } else {
        ans = T - D * (X - M);
    }
    printf("%d\n", ans);
    return 0;
}