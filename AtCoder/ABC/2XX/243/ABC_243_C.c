//2022/07/18 00:10:43
//
#include <stdio.h>
#include <limits.h>
#define NUM 200000
int main(void){
    int N, X[NUM], Y[NUM];
    int hoge[NUM][2], Y_list[NUM];
    char S[NUM + 1];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        hoge[i][0] = INT_MAX;
        hoge[i][1] = -1;
        Y_list[i] = -1;
        int flag = 1, j = 0;
        for (; Y_list[j] != -1; j++) {
            if (Y_list[j] == Y[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            Y_list[j] = Y[i];
        }
    }
    scanf("%s", S);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L' && hoge[Y[i]][1] < X[i]) {
            hoge[Y[i]][1] = X[i];
        }
        if (S[i] == 'R' && X[i] < hoge[Y[i]][0]) {
            hoge[Y[i]][0] = X[i];
        }
    }
    for (int i = 0; Y_list[i] != -1; i++) {
        if (hoge[Y_list[i]][0] < hoge[Y_list[i]][1]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
//各y座標について一番左のRと一番右のLを見れば良い