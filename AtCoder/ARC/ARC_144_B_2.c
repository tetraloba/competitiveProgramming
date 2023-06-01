//2022/07/16 21:15:43
//2022/07/16 21:57:33 TLE
#include <stdio.h>
#include <limits.h>
void scan1(int*, int, int*, int*);
void scan2(int*, int, int*, int*, int*, int*);
int f_min(int, int);
int main(void){
    int N, a, b, A[300000];
    scanf("%d %d %d", &N, &a, &b);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int mi1, mi2, ma2, ma1;
    scan2(A, N, &mi1, &mi2, &ma1, &ma2);
    int n = f_min((A[mi2] - A[mi1]) / a, (A[ma1] - A[ma2]) / b);
    A[mi1] += a * n;
    A[ma1] -= b * n;
    int mi, ma;
    while (1) {
        scan1(A, N, &mi, &ma);
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
void scan1(int *A, int N, int *mi, int *ma){
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
void scan2(int *A, int N, int *mi1, int *mi2, int *ma2, int *ma1){
    int min = INT_MAX, max = INT_MIN;
    *mi2 = *ma2 = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
            *mi2 = *mi1;
            *mi1 = i;
        }
        if (max < A[i]) {
            max = A[i];
            *ma2 = *ma1;
            *ma1 = i;
        }
    }
    if (*mi2 == -1 || *ma2 == -1) {
        for (int i = 0; i < N; i++) {
            if (A[i] < min) {
                min = A[i];
                *mi2 = *mi1;
                *mi1 = i;
            }
            if (max < A[i]) {
                max = A[i];
                *ma2 = *ma1;
                *ma1 = i;
            }
        }
    }
    return;
}
int f_min(int a, int b){
    if (a < b) {
        return a;
    }
    return b;
}