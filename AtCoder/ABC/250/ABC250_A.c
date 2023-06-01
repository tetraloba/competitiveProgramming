//2022/07/04 15:25
//2022/07/04 15:32 AC.
#include <stdio.h>
int main(void){
    int H, W, R, C;
    scanf("%d %d %d %d", &H, &W, &R, &C);
    int ans = 0;
    if (1 < R) {
        ans++;
    }
    if (R < H) {
        ans++;
    }
    if (1 < C) {
        ans++;
    }
    if (C < W) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}