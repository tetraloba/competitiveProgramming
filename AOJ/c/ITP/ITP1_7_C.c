#include <stdio.h>
int main(void) {
    int r, c, arr[100][100], sum = 0;
    int sumr[100] = {0}, sumc[100] = {0};
    //表のサイズ指定
    scanf("%d %d", &r, &c);
    //表の読み込みと各行の合計値
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            sumr[i] += arr[i][j];
        }
    }
    //各列の合計値とすべての合計
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sumc[i] += arr[j][i];
        }
        sum += sumc[i];
    }
    //r行目まで出力
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("%d\n", sumr[i]);
    }
    //r+1行目の出力
    for (int i = 0; i < c; i++) {
        printf("%d ", sumc[i]);
    }
    printf("%d\n", sum);

    return 0;
}