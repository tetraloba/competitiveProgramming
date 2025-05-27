//2022/07/03 16:47
//2022/07/03 17:02 TLE.
#include <stdio.h>
int unique(int*, int, int); //整数値が配列に含まれていなければ1を返す。含まれていれば0を返す。
int main(void){
    int N, W, A[302];
    int arr_n[1000000]; //良い整数
    scanf("%d %d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int count = 0;
    A[N] = A[N + 1] = 0; //後ろに、3つ選ばない(1つor2つの)時用の0を追加
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            for (int k = j + 1; k < N + 2; k++) {
                if (A[i] + A[j] + A[k] <= W && unique(arr_n, A[i] + A[j] + A[k], count)) {
                    // printf("A[%d]:%d, A[%d]:%d, A[%d]:%d\n", i, A[i], j, A[j], k, A[k]);
                    arr_n[count] = A[i] + A[j] + A[k];
                    count++;
                } 
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
int unique(int arr[], int a, int N){
    for (int i = 0; i < N; i++) {
        if (arr[i] == a) {
            return 0;
        }
    }
    return 1;
}