//2022-07-23 20:39:58
//2022-07-23 20:58:27 中断。ABC受けるため
//2022-07-26 20:13:05 再開
//2022-07-26 20:25:33 WA, TLE
#include <stdio.h>
int func(int, int*, int);
int main(void){
    int N, X, dif[100];
    scanf("%d %d", &N, &X);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int tmpa, tmpb;
        scanf("%d %d", &tmpa, &tmpb);
        sum += tmpa;
        dif[i] = tmpb - tmpa;
    }
    int tgt = X - sum;
    if (func(tgt, dif, N)) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
int func(int tgt, int arr[], int n){
    for (int i = 0; i < n; i++) {
        if ((arr[i] < tgt && func(tgt - arr[i], &arr[i + 1], n - i - 1)) || tgt == arr[i]) {
            return 1;
        }
    }
    return 0;
}
//dif配列から好きなだけ選んで(重複なし)、X - sumを作れるかどうか、やな。(2022-07-23 20:46:27)
//再帰で書けるな。