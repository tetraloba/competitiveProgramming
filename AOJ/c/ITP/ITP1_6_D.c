#include <stdio.h>
int main(void){
    int n, m;
    scanf(" %d %d", &n, &m);
    int A[n][m], b[m], c[n];    //配列の要素の個数に変数使ってるの良くはない。変数使わないバージョン(100配列ver.)も作ってもいいかも。

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &A[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf(" %d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            num += A[i][j] * b[j];
        }
        printf("%d\n", num);
    }

    return 0;
}