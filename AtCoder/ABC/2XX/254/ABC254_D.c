//2022/06/04 21:37
//2022/06/04 21:56 TLE, WA
//2022/06/04 22:10 TLE
#include <stdio.h>
int func_yakusuu(long long int, int);
int main(void){
    int N, count = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        count += func_yakusuu(i * i, N);
        /*debug
        printf("%d:%d\n", i * i, func_yakusuu(i * i, N));
        */
    }
    printf("%d\n", count);
    return 0;
}
int func_yakusuu(long long int a, int b){
    int N, count = 0;
    if (a < b) {
        N = a;
    } else {
        N = b;
    }
    int i; //若干早くなるかなって
    if (a / b) {
        i = a / b;
    } else {
        i = 1;
    }
    for (; i <= N; i++) {
        if (a % i == 0 && a / i <= b) {
            count++;
        }
    }
    return count;
}