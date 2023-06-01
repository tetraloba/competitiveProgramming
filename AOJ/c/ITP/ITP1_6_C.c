#include <stdio.h>
int main(void){
    int n, b, f, r, v, people[4][3][10] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &b, &f, &r, &v);
        people[b-1][f-1][r-1] += v;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                printf(" %d", people[i][j][k]);
            }
            putchar('\n');
        }
        if (i < 3) {
            puts("####################");
        }
    }

    return 0;
}