// 2023/06/16 00:24:09
// 2023/06/16 00:37:32 AC.
#include <stdio.h>
#include <stdlib.h> // malloc
int main(void){
    int N;
    scanf("%d", &N);
    int *A = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int maxEven[2] = {-1, -1};
    int maxOdd[2] = {-1, -1};
    for (int i = 0; i < N; i++) {
        if (A[i] % 2) {
            if (maxOdd[1] < A[i]) {
                maxOdd[0] = maxOdd[1];
                maxOdd[1] = A[i];
            } else if (maxOdd[0] < A[i]) {
                maxOdd[0] = A[i];
            }
        } else {
            if (maxEven[1] < A[i]) {
                maxEven[0] = maxEven[1];
                maxEven[1] = A[i];
            } else if (maxEven[0] < A[i]) {
                maxEven[0] = A[i];
            }
        }
    }
    free(A);

    int ans = -1;
    if (maxEven[0] != -1) {
        ans = maxEven[0] + maxEven[1];
    }
    if (maxOdd[0] != -1 && ans < maxOdd[0] + maxOdd[1]) {
        ans = maxOdd[0] + maxOdd[1];
    }
    printf("%d\n", ans);
    return 0;
}