#include <stdio.h>
#include <limits.h>
int min(int, int);
int main(void){
    int N, W[200000];
    char S[200001];
    int min1 = INT_MAX, max0 = 0; //min1:1(大人)の最小値, max0:0(子供)の最大値
    scanf("%d %s", &N, S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
        if (S[i] == '0') {
            if (max0 < W[i]) {
                max0 = W[i];
            }
        } else {
            if (W[i] < min1) {
                min1 = W[i];
            }
        }
    }
    int count0 = 0, count1 = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            if (min1 <= W[i]) {
                count0++; //min1(大人の最小値)以上の0(子供)の数
            }
        } else {
            if (W[i] <= max0) {
                count1++; //max0(子供の最大値)以下の1(大人)の数
            }
        }
    }
    int r_ans; //誤答数
    if (!count0 || !count0) {
        r_ans = 0;
    } else {
        r_ans = min(count0, count1);
    }
    printf("%d\n", N - r_ans);
    return 0;
}
int min(int a, int b){
    if (a < b) {
        return a;
    }
    return b;
}

// 30 60 80
// 40 45
//間違える人数を考える？
//W1の最小より大きいW0の数と、W0の最大より大きいW1の数、これらの小さい方が間違える最少人数？
//W0の初期値は0, W1の初期値はINT_MAX??
//0ならbreak;
//50 60 60
//50 50
//40 60 80 100
//20 40 60 80 80
//count0 = 4 + (最小重複)
//count1 = 3 + (最大重複)
//r_ans = 4
//いや90にしたらr_ans = 3やんけ。重複関係ないわ。
//40 40 60 80
//20 40 60
//count0 = 2
//count1 = 3
//r_ans = 2
//40 40 61 80
//20 40 60
//40 40 60 80 100
//40 60
//count0 = 2
//count1 = 3
//r_ans = 2;
//40 40 60 80 100
//60 80 80
//count0 = 3
//count1 = 4
//r_ans = 3