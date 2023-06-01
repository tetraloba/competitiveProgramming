//2022-07-24 11:22:07
//2022-07-24 12:25:23 AC.
#include <stdio.h>
#include <stdlib.h>
int cmpFunc(const void*, const void*);
int main(void){
    int N, K, X, A[200000];
    scanf("%d %d %d", &N, &K, &X);
    long sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (X < A[i]) {
            if (A[i] / X < K) {
                K -= A[i] / X;
                A[i] %= X;
            } else {
                A[i] -= K * X;
                K = 0;
            }
        }
        sum += A[i];
    }
    qsort(A, N, sizeof(A[0]), cmpFunc);
    if (N <= K) {
        sum = 0;
    } else {
        for (int i = 0; i < K; i++) {
            sum -= A[i];
        }
    }
    printf("%ld\n", 0 < sum ? sum : 0);
    return 0;
}
int cmpFunc(const void *n1, const void *n2) {
    if (*(int*)n1 < *(int*)n2) {
        return 1;
    } else if (*(int*)n2 < *(int*)n1) {
        return -1;
    } else {
        return 0;
    }
}
//初めてのqsort。中身は知らない。