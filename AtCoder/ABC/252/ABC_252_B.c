#include <stdio.h>
int main(void){
    int N, K, A[100], B[100], A_max = 0;
    scanf("%d %d", &N, &K);
    //printf("N=%d, K=%d\n", N, K); //debag
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        //printf("A[%d]=%d\n", i, A[i]); //debag
        if (A_max < A[i]) {
            A_max = A[i];
        }
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &B[i]);
        //printf("B[%d]=%d/n", i, B[i]); //debag
    }
    int judge = 0;
    for (int i = 0; i < K; i++) {
        if (A[B[i]-1] == A_max) { // <- Be careful!
            puts("Yes");
            judge = 1;
            break;
        }
    }
    if (judge == 0) {
        puts("No");
    }
    return 0;
}