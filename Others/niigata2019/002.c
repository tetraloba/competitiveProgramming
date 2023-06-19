//  [新潟大2019編入(2)]
// 1~99までの整数のうち4つの数（重複可）を入力し、入力された数をつなぎ合わせて最大となる数を出力するC言語プログラムを作成せよ。
// 例えば、4、6、77、9を入力した場合、97764が答えとなる。
// 使用した変数やプログラムの動作に関する部分には可能な限りコメントをつけること。

#include <stdio.h>
#define NUM 4 // 入力する整数の数

/* 結合関数: a と b を結合した ab を返す */
int combine(int a, int b){ // 結合関数
    int t = b;
    while (t) {
        a *= 10;
        t /= 10;
    }
    return a + b;
}
int main(void){
    int const N = NUM; // 入力する整数の数
    int arr[NUM];
    /* 入力 */
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int max = 0;
    /* 全探索 */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) {
                    continue;
                }
                int l = 6 - i - j - k;
                /* arr[i],arr[j],arr[k],arr[l] の順に結合したものが max より大きければ max を更新 */
                int tmp = combine(combine(arr[i], arr[j]), combine(arr[k], arr[l]));
                if (max < tmp) {
                    max = tmp;
                }
            }
        }
    }
    /* 出力 */
    printf("%d\n", max);
    return 0;
}
// 全探索
// 0 1 2 3
// 0 1 3 2
// 0 2 1 3
// 0 2 3 1
// 0 3 1 2
// 0 3 2 1
// 1 0 2 3
// 1 0 3 2
// 1 2 0 3
// 1 2 3 0
// 1 3 0 2
// 1 3 2 0
// 2 0 1 3