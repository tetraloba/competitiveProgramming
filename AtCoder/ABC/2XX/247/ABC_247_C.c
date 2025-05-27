//2022/07/06 17:35
//2022/07/06 17:58 WA
//2022/07/06 18:01 WA
//2022/07/06 18:13 AC.
#include <stdio.h>
int main(void){
    int N;
    scanf("%d", &N);
    int ans[65536] = {0};
    ans[0] = 1;
    int n = 1;
    for (int i = 2; i <= N; i++) {
        ans[n] = i;
        for (int j = n + 1; j <= 2 * n; j++) {
            ans[j] = ans[j - (n + 1)];
        }
        n = 2 * n + 1;
    }
    // printf("%d\n", n);
    for (int i = 0; ans[i]; i++) {
        printf("%d", ans[i]);
        if (ans[i + 1]) {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}
//配列何文字分？配列使わずに解ける？
//1 1
//2 3
//3 7
//4 15
//16 65535
//0出てこないからint配列でも可？