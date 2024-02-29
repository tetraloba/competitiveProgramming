// 2024/02/28 18:53:36
// 2024/02/28 19:10:10 TLE やっぱ無理か(笑)
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    int *A = (int*)malloc(sizeof(int) * N);
    int *B = (int*)malloc(sizeof(int) * M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += A[i] + B[j] < P ? A[i] + B[j] : P;
        }
    }
    free(A);
    free(B);
    printf("%lld\n", ans);
    return 0;
}