//2022/07/01 17:22
//2022/07/01 19:13 AC.
//jとaiとi-jを求める。 iはcount, aiはjから求める(jはjudgeが返してfuncがリレー), i - jは各々から計算。
#include <stdio.h>
int pow(int, int);
int judge(int, int*, int);
int func(int, int, int*, int*);
int main(void){
    int a, L, result[21]; //1<=L<=6, 0<=a<10^L, ansはカウント, resultは引き算の結果を格納する配列
    while (1) {
        //入力
        scanf("%d %d", &a, &L);
        if (a == 0 && L == 0) {
            break;
        }
        result[0] = a;
        int count = 1;
        int ans_j = func(a, L, &count, result);
        printf("%d %d %d\n", ans_j, result[count], count - ans_j);
    }
    return 0;
}
int func(int a, int L, int *p_count, int *result){
    int ans_j;
    //前処理
    char str[7];
    for (int i = L - 1; i >= 0; i--) {
        str[i] = '0' + a % 10;
        a /= 10;
    }
    //降順sort
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < L - 1; i++) {
            if (str[i] < str[i + 1]) {
                char tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
                flag = 1;
            }
        }
    }
    //最大値と最小値生成
    int max = 0, min = 0;
    for (int i = 0; i < L; i++) {
        max += (str[i] - '0') * pow(10, L - i - 1);
    }
    for (int i = 0; i < L; i++) {
        min += (str[i] - '0') * pow(10, i);
    }
    //引き算の結果を格納
    result[*p_count] = max - min;
    if ((ans_j = judge(result[*p_count], result, *p_count) - 1) + 1) {
        return ans_j;
    } else {
        (*p_count)++;
        return func(result[(*p_count - 1)], L, p_count, result);
    }
}
int pow(int a, int b){
    int n = 1;
    for (int i = 0; i < b; i++) {
        n *= a;
    }
    return n;
}
int judge(int a, int *result, int N){
    for (int j = 0; j < N; j++) {
        if (a == *result) {
            return j + 1;
        }
        result++;
    }
    return 0;
}