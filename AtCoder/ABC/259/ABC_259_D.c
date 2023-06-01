//2022/07/09 21:58
//
#include <stdio.h>
#include <math.h>
//２つの値の差の絶対値を返す
int dif(int a, int b){
    if (a < b) {
        return b - a;
    }
    return a - b;
}
//平面上の２つの点の距離を返す
double dis(int x1, int y1, int x2, int y2){//順番注意
    return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}
int main(void){
    int N, s[2], t[2], cir[3000][3]; //cirはx, y, r
    scanf("%d %d %d %d %d", &N, &s[0], &s[1], &t[0], &t[1]);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &cir[i][0], &cir[i][1], &cir[i][2]);
    }
    for (int i = 0; i < N; i++) {
        //開始点に接する円を捜索
        if ((s[0] == cir[i][0] && (s[1] == cir[i][1] + cir[i][2] || s[1] == cir[i][1] - cir[i][2])) 
        || (s[1] == cir[i][1] && (s[0] == cir[i][0] + cir[i][2] || s[0] == cir[i][0] - cir[i][2]))) {
            //その円が交わるまたは接する円にフラグを付ける
            int flag[3000] = {0};
            flag[i] = 1;
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                double d = dis(cir[i][0], cir[i][1], cir[j][0], cir[j][1]); //円の(中心点の)距離
                printf("%f : %d\n", d, cir[i][2] + cir[j][2]);
                if (dif(cir[i][2], cir[j][2]) <= d && d <= cir[i][2] + cir[j][2]) {
                    flag[j] = 1;
                }
            }
            for (int k = 0; k < N; k++) {
                printf("%d:%d\n", k, flag[k]);
            }
        }
    }
    return 0;
}
//点どうしの距離よりも半径の合計が大きければ円が接する(移動できる) ->とは限らない。円が含まれる場合。点の距離がいずれかの半径より大きい必要がある。
//つまり|r1 - r2| <= d <= r1 + r2
//接するやつはグループ化していく？

//sに接する各円について、|r1 - r2| <= d <= r1 + r2を満たす円にフラグを付けていく。その円が|r1 - r2| <= d <= r1 + r2を満たすものもフラグを付ける。
//計算量膨大やな。ダブりが生じないように上手くやらないと…円のIDが自分より大きいものについてのみ調べる。
//再帰使えばきれいに書けそう。
//目的の点に接する(=点の距離と半径が等しい)円にフラグが付けばYes