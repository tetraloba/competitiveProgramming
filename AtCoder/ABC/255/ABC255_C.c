//2022/06/11 21:45
//2022/06/11 23:18 WA.
#include <stdio.h>
long long dif(long long, long long);
int main(void){
    long long X, A, N, min;
    int D;
    scanf("%lld %lld %d %lld", &X, &A, &D, &N);
    if (!D) {
        printf("%lld\n", dif(X, A));
    } else if ((X - A) / D < 0) {
        printf("%lld\n", X - A);
    } else if (N < ((X - A) / D)) {
        // printf("%lld : %lld\n", N, ((X - A) / D)); //debug
        printf("%lld\n", dif(X, A + D * (N - 1)));
    } else {
        long long i = (X - A) / D;
        min = dif(X, A + D * i);
        if (dif(X, A + D * (i + 1)) < min) {
            min = dif(X, A + D * (i + 1));
        }
        // printf("%lld : %lld\n", dif(X, A + D * i), min); //debug
        printf("%lld\n", min);
    }
    return 0;
}
long long dif(long long a, long long b){
    long long d = a - b;
    if (d < 0) {
        return -d;
    } else {
        return d;
    }
}