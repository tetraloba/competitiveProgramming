#include <stdio.h>
int main(void){
    int n[2][3], ans[2];
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &n[0][i], &n[1][i]);
    }
    for (int i = 0; i < 2; i++) {
        if (n[i][0] == n[i][1]) {
            ans[i] = n[i][2];
        } else if (n[i][0] == n[i][2]) {
            ans[i] = n[i][1];
        } else {
            ans[i] = n[i][0];
        }
    }
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}