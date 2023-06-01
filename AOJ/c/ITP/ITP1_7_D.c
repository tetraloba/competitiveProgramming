#include <stdio.h>
int main(void){
    int n, m, l, arr_a[100][100], arr_b[100][100];
    long long arr_c[100][100] = {0};
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr_a[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &arr_b[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                arr_c[i][j] += arr_a[i][k] * arr_b[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            printf("%lld", arr_c[i][j]);
            if (j != l - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}