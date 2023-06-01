//2022/07/17 22:24:33
//2022/07/17 22:43:23 無理
//2022/07/17 23:17:38 TLE
#include <stdio.h>
#include <limits.h>
#define NUM 200000
int Min(int*, int, int);
int main(void){
    int N, K, P[NUM], flag[NUM], top[NUM] = {0}, num[NUM] = {0}, time[NUM];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        flag[i] = NUM;
        time[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        int index = Min(top, N, P[i]);
        if (index == -1) {
            for (int j = 0; j < N; j++) {
                if (!top[j]) {
                    top[j] = P[i];
                    num[j]++;
                    flag[i] = j;
                    index = j;
                    break;
                }
            }
        } else {
            top[index] = P[i];
            num[index]++;
            flag[i] = index;
        }
        if (num[index] >= K) {
            num[index] = 0;
            top[index] = 0;
            for (int j = 0; j < N; j++) {
                if (flag[j] == index) {
                    flag[j] = -1;
                    time[P[j] - 1] = i + 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", time[i]);
    }
    return 0;
}
int Min(int top[], int N, int X) {
    int min = INT_MAX, min_i = -1;
    for (int i = 0; i < N; i++) {
        if (X <= top[i] && top[i] < min) {
            min = top[i];
            min_i = i;
        }
    }
    return min_i;
}