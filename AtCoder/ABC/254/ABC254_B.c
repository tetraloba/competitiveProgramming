//2022/06/04 21:05
//2022/06/04 21:16 AC
#include <stdio.h>
int main(void){
    int N, A[30][30] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                A[i][j] = 1;
            } else {
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            }
            printf("%d", A[i][j]);
            if (j == i) {
                putchar('\n');
            } else {
                putchar(' ');
            }
        }
    }
    return 0;
}