//2022/07/17 21:03:41
//
#include <stdio.h>
#include <limits.h>
int max(int*, int);
int main(void){
    int N, X, Y, Z;
    int A[1000], B[1000], SUM[1000], F[1000];
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
    for (int i = 0; count < X; i++) {
        if (F[i] && A[i] == max(A, N)) {
            F[i] = 0;
            A[i] = B[i] = SUM[i] = -1;
            i = 0;
            count++;
        }
    }
    count = 0;
    for (int i = 0; count < Y; i++) {
        if (F[i] && B[i] == max(B, N)) {
            F[i] = 0;
            A[i] = B[i] = SUM[i] = -1;
            i = 0;
            count++;
        }
    }
    count = 0;
    for (int i = 0; count < Z; i++) {
        if (F[i] && SUM[i] == max(SUM, N)) {
            F[i] = 0;
            A[i] = B[i] = SUM[i] = -1;
            i = 0;
            count++;
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