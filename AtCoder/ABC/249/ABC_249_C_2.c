//2022/07/25 15:32:20
//2022/07/25 17:33:15 AC.
#include <stdio.h>
#define NUM 32 //文字列の長さ????
int funcPow(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int main(void){
    int N, K, arr[15][26] = {0};
    int ans = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        char tmpS[NUM];
        scanf("%s", tmpS);
        for (int j = 0; tmpS[j]; j++) {
            arr[i][tmpS[j] - 'a'] = 1;
        }
    }
    int limit = funcPow(2, N);
    for (int cnt = 1; cnt < limit; cnt++) {
        int sum[26] = {0};
        for (int i = 0; i < N; i++) {
            int tmp = funcPow(2, i);
            if (cnt % (tmp * 2) / tmp){
                for (int j = 0; j < 26; j++) {
                    sum[j] += arr[i][j];
                }
            }
        }
        // for (int i = 0; i < 26; i++) {
        //     printf("%d ", sum[i]);
        // }
        // putchar('\n');
        int tmp_ans = 0;
        for (int i = 0; i < 26; i++) {
            if (sum[i] == K) {
                tmp_ans++;
            }
        }
        if (ans < tmp_ans) {
            ans = tmp_ans;
        }
    }
    // for (int i = 0; i < N; i++) {
    //     printf("%d: ", i);
    //     for (int j = 0; j < 26; j++) {
    //         printf("%d ", arr[i][j]);
    //     }
    //     putchar('\n');
    // }
    printf("%d\n", ans);
    return 0;
}
//選ぶ文字列の組み合わせは2^15通り
//文字列の中に含まれるアルファベットの構成は2^26通り