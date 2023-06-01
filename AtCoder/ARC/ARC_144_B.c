//2022/07/16 21:15:43
//2022/07/16 21:57:33 TLE
#include <stdio.h>
#include <limits.h>
void scan(int*, int, int*, int*);
int main(void){
    int N, a, b, A[300000];
    scanf("%d %d %d", &N, &a, &b);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int mi, ma;
    while (1) {
        scan(A, N, &mi, &ma);
        if (A[mi] < A[ma] - b) {
            A[mi] += a;
            A[ma] -= b;
        } else {
            break;
        }
    }
    printf("%d\n", A[mi]);
    return 0;
}
void scan(int *A, int N, int *mi, int *ma){
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
            *mi = i;
        }
        if (max < A[i]) {
            max = A[i];
            *ma = i;
        }
    }
    return;
}