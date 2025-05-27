//2022/06/25 21:05
//2022/06/25 21:25 AC.
#include <stdio.h>
int main(void){
    int N, K, Q, A[200], L[1000];
    scanf("%d %d %d", &N, &K, &Q);
    for (int i = 0; i < K; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d", &L[i]);
    }
    for (int i = 0; i < Q; i++) {
        if (A[L[i] - 1] == N) {
            // putchar('#');
        } else if (A[L[i] + 1 - 1] == A[L[i] - 1] + 1) {
            // putchar('$');
        } else {
            // printf("A[L[%d] - 1]:%d, L[%d]:%d\n", i, A[L[i] - 1], i, L[i]);
            A[L[i] - 1]++;
        }
    }
    for (int i = 0; i < K; i++) {
        printf("%d", A[i]);
        if (i != K - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    return 0;
}