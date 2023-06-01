//2022/07/01 20:53
//2022/07/01 21:03 AC.
#include <stdio.h>
int max(int*, int);
int main(void){
    int n, m; //1<=n<=1000, 1<=m<=50
    int sum[1000]; //各生徒の合計点
    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m) {
            break;
        }
        //配列sumの初期化
        for (int i = 0; i < n; i++) {
            sum[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);
                sum[j] += tmp;
            }
        }
        printf("%d\n", max(sum, n));
    }
    return 0;
}
int max(int *arr, int n) {
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (max < *arr) {
            max = *arr;
        }
        arr++;
    }
    return max;
}