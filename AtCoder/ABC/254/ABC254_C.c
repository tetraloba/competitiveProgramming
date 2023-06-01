//2022/06/04 21:16
//2022/06/04 21:27 TLE
#include <stdio.h>
int main(void){
    int N, K, A[200000];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int check = 1;
    while (check) {
        check = 0;
        for (int i = 0; i < N - K; i++) {
            if (A[i + K] < A[i]) {
                int tmp = A[i + K];
                A[i + K] = A[i];
                A[i] = tmp;
                check = 1;
            }
        }
    }
    /*debug
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    putchar('\n');
    */
    for (int i = 0; i < N - 1; i++) {
        if (A[i + 1] < A[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}