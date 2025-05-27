//2022/07/17 21:03:41
//
#include <stdio.h>
#include <limits.h>
int max(int*, int);
int main(void){
    int N, X, Y, Z;
    int A[1005], B[1005], SUM[1005], F[1005];
    scanf("%d %d %d %d", &N, &X, &Y, &Z);
    for (int i = 0; i < N; i++) {
        F[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        SUM[i] = A[i] + B[i];
    }
    int count = 0;
    while (1) {
        for (int i = 0; i < N; i++) {
            if (count >= X) {
                break;
            }
            if (F[i] && A[i] >= max(A, N)) {
                F[i] = 0;
                A[i] = B[i] = SUM[i] = -1;
                i = 0;
                count++;
            }
        }
        if (count >= X) {
            break;
        }
    }
    count = 0;
    while (1) {
        for (int i = 0; i < N; i++) {
            if (count >= Y) {
                break;
            }
            if (F[i] && B[i] >= max(B, N)) {
                F[i] = 0;
                A[i] = B[i] = SUM[i] = -1;
                i = 0;
                count++;
            }
        }
        if (count >= Y) {
            break;
        }
    }
    count = 0;
    while (1) {
        for (int i = 0; i < N; i++) {
            if (count >= Z) {
                break;
            }
            if (F[i] && SUM[i] >= max(SUM, N)) {
                F[i] = 0;
                A[i] = B[i] = SUM[i] = -1;
                i = 0;
                count++;
            }
        }
        if (count >= Z) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!F[i]) {
            printf("%d\n", i + 1);
        }
    }
    return 0;
}
int max(int A[], int N){
    int max = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}