//方針：x軸とy軸でそれぞれ要素数32の配列作って重なった枚数記録するのが無難じゃね？
//→32じゃなくて63かな。
//→63じゃなくて462かな。→通った！！ 461でも通るけど多分理論値は462。
#include <stdio.h>
int main(void){
    int n, m, t, p, d, c, x, y;
    while (1) {
        int l = 0, u = 0; //l:左端のx座標, u:下端のy座標
        int px[462] = {0}, py[462] = {0}; //紙のx軸y軸それぞれの重なった枚数
        int hole[20]; //p回分の穴の数を記録
        scanf("%d %d %d %d", &n, &m, &t, &p);
        //0 0 0 0でなければ実行
        if (n || m || t || p) {
            //n * mの1枚の紙を設置
            for (int i = 0; i < n; i++) {
                px[i] = 1;
            }
            for (int i = 0; i < m; i++) {
                py[i] = 1;
            }
            //t回折る処理
            for (int i = 0; i < t; i++) {
                scanf("%d %d", &d, &c);
                if (d == 1) {
                    l += c; //折り目まで左端が移動
                    //px[l] ~ px[l + c]は穴の空く数が2倍になる
                    for (int j = 0; j < c; j++) {
                        px[l + j] += px[l - j - 1];
                    }
                } else { //d==2の時
                    u += c; //折り目まで下端が移動
                    //py[u] ~ py[u + c]は穴の空く数が2倍になる
                    for (int j = 0; j < c; j++) {
                        py[u + j] += py[u - j - 1];
                    }
                }
            }
            //穴が空く数をp回分記録する処理
            for (int i = 0; i < p; i++) {
                scanf("%d %d", &x, &y);
                hole[i] = px[l + x] * py[u + y];
            }
            for (int i = 0; i < p; i++) {
                printf("%d\n", hole[i]);
            }
        } else {
            return 0;
        }
    }
}