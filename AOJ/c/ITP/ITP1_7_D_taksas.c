#include <stdio.h>


int main(void) {
    int n, m, l, hyo1[100][100] = {0},hyo2[100][100] = {0}, result[100][100] = {0};
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &hyo1[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &hyo2[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += hyo1[i][k] * hyo2[k][j];
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            if ( j != l - 1) {
                printf("%d ", result[i][j]);
            } else {
                printf("%d", result[i][j]);
            }
        }
        if ( i != n - 1) {
            printf("\n");
        }
    }
    putchar('\n');


    return 0;
}

/*/
11

11 11   1 1
12 21   2 0


12              

11 12   1*2
12 22   2* 3

/*/