#include <stdio.h>
int main(void) {
    //表の読み込みと各行の合計値
    int r, c, sum = 0;
    scanf("%d %d", &r, &c);
    printf("r=%d c=%d\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("i=%d j=%d\n", i, j);
            scanf("%d", &sum);
        }
    }
    return 0;
}