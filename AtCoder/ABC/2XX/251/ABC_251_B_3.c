//2022/07/03 16:47
//2022/07/03 17:02 TLE.
//2022/07/03 17:14 AC.
#include <stdio.h>
int main(void){
    int N, W, A[302];
    int arr_n[1000000] = {0}; //良い整数(flag)
    scanf("%d %d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    A[N] = A[N + 1] = 0; //後ろに、3つ選ばない(1つor2つの)時用の0を追加
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            for (int k = j + 1; k < N + 2; k++) {
                if (A[i] + A[j] + A[k] <= W) {
                    // printf("A[%d]:%d, A[%d]:%d, A[%d]:%d\n", i, A[i], j, A[j], k, A[k]);
                    arr_n[A[i] + A[j] + A[k] - 1]++;
                } 
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 1000000; i++) {
        if (arr_n[i]) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}