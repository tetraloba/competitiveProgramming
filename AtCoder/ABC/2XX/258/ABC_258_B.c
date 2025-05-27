//2022/07/02 21:01
//2022/07/02 23:06 WA.
//2022/07/02 23:18 AC.
#include <stdio.h>
long long int pow(int, int);
long long int func_max(long long int*, int); //配列の要素の最大値を返す
int main(void){
    int N, A[10][10];
    long long int max100[100] = {0}; //各出発点における最大値
    //入力
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long int tmp;
        scanf("%lld", &tmp);
        for (int j = N - 1; 0 <= j; j--) {
            A[i][j] = (int)(tmp / pow(10, N - 1 - j) % 10);
        }
    }
    //各出発点について全8方向それぞれに進んだ場合の最大値を求める。
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            long long int value8[8] = {0}; //8方向に進んだときそれぞれの値
            //+x方向
            int x = k;
            int y = l;
            for (int i = 0; i < N; i++) {
                value8[0] += A[x][y] * pow(10, N - 1 - i);
                x++;
                if (N - 1 < x) {
                    x = 0;
                }
            }
            //+x+y方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[1] += A[x][y] * pow(10, N - 1 - i);
                x++;
                y++;
                if (N - 1 < x) {
                    x = 0;
                }
                if (N - 1 < y) {
                    y = 0;
                }
            }
            //+y方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[2] += A[x][y] * pow(10, N - 1 - i);
                y++;
                if (N - 1 < y) {
                    y = 0;
                }
            }
            //-x+y方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[3] += A[x][y] * pow(10, N - 1 - i);
                x--;
                y++;
                if (x < 0) {
                    x = N - 1;
                }
                if (N - 1 < y) {
                    y = 0;
                }
            }
            //-x方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[4] += A[x][y] * pow(10, N - 1 - i);
                x--;
                if (x < 0) {
                    x = N - 1;
                }
            }
            //-x-y方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[5] += A[x][y] * pow(10, N - 1 - i);
                x--;
                y--;
                if (x < 0) {
                    x = N - 1;
                }
                if (y < 0) {
                    y = N - 1;
                }
            }
            x = k;
            y = l;
            //-y方向
            for (int i = 0; i < N; i++) {
                value8[6] += A[x][y] * pow(10, N - 1 - i);
                y--;
                if (y < 0) {
                    y = N - 1;
                }
            }
            //+x-y方向
            x = k;
            y = l;
            for (int i = 0; i < N; i++) {
                value8[7] += A[x][y] * pow(10, N - 1 - i);
                x++;
                y--;
                if (N - 1 < x) {
                    x = 0;
                }
                if (y < 0) {
                    y = N - 1;
                }
            }
            //8方向の中での最大値をその出発点の値とする。
            max100[k * N + l] = func_max(value8, 8);
        }
    }
    //出力
    printf("%lld\n", func_max(max100, 100));
    return 0;
}
long long int pow(int a, int b){
    int n = 1;
    for (int i = 0; i < b; i++) {
        n *= a;
    }
    return n;
}
long long int func_max(long long int arr_p[], int N){
    long long int max = 0;
    for (int i = 0; i < N; i++) {
        if (max < arr_p[i]) {
            max = arr_p[i];
        }
    }
    return max;
}
//最大値から初めて最大値がある向きに移動する
//最大値が複数ある場合は…？→隣接の最大値→さらに隣接の最大値…
//結局全部試して最大値求めるほうが早そう。