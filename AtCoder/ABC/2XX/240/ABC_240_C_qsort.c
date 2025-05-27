//2022-07-23 20:39:58
//2022-07-23 20:58:27 中断。ABC受けるため
//2022-07-26 20:13:05 再開
//2022-07-26 20:25:33 WA, TLE
#include <stdio.h>
#include <stdlib.h>
int func(int, int*, int);
int funcCmp(const void*, const void*);
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
    qsort(dif, N, sizeof(dif[0]), funcCmp); //不要か? 降順に並べ替えたほうがやや早くなるかも? ->遅くなったわ
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
        if (arr[i] < tgt && func(tgt - arr[i], &arr[i + 1], n - i - 1)) {
            return 1;
        }
        if (tgt == arr[i]) {
            return 1;
        }
    }
    return 0;
}
int funcCmp(const void *a, const void *b){
    if (*(int*)a < *(int*)b) {
        return 1;
    } else if (*(int*)b < *(int*)a) {
        return -1;
    } else {
        return 0;
    }
}
//dif配列から好きなだけ選んで(重複なし)、X - sumを作れるかどうか、やな。(2022-07-23 20:46:27)
//再帰で書けるな。