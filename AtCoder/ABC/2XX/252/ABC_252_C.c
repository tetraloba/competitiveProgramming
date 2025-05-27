#include <stdio.h>
int dif_time(int n1, int n2){ //もっと簡単に計算できるハズ…？ 今の頭じゃ無理。。。
    if (0 < n2 - n1) {
        return n2 - n1;
    } else {
        return n2 - n1 + 10;
    }
}
int main(void){
    int N, ans = 990;
    char S[100][11];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s", S[i]);
    }
    int dif = '0' - 0;
    int hoge;
    for (int i = 0; i < 10; i++) { //走査する番号
        int finish[100] = {0};
        int time = 0;
        while (1) { //時間
            for (int j = 0; j < N; j++) { //jはリール
                if (i == S[j][time % 10] - dif && finish[j] != 1) { //t%10!!
                    finish[j] = 1;
                    break;
                }
            }
            int flag = 0;
            for (int k = 0; k < N; k++) {
                if (finish[k] == 0) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                break;
            }
            time++;
        }
        if (time < ans) {
            ans = time;
        }
    }
    printf("%d\n", ans);
    return 0;
}

//ctrl + shift + L