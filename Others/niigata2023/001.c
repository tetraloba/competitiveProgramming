#include <stdio.h>
// a と b が互いに素なら1, さもなくば0
int tagainiso(int a, int b){
    for (int i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            return 0;
        }
    }
    return 1;
}
// 素因数の積
long long rad(long long n){
    // int soinsuuStack[1000];
    // int stackSize = 0;
    // for (int i = 1; i < n; i++) {
    //     if (n % i == 0) {
    //         soinsuuStack[stackSize++] = i;
    //     }
    // }
    // int ans = 1;
    // for (int i = 0; i < stackSize; i++) {
    //     ans *= soinsuuStack[i];
    // }
    // return ans;
    long long ans = 1;
    for (long long i = 2; i <= n; i++) {
        if (n % i == 0 && ans % i != 0) {
            ans *= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    return ans;
}
int main(void){
    puts("a\tb\tc\trad(a * b * c)");
    for (int c = 1; c < 1000; c++) {
        for (int a = 1; a < c / 2; a++) {
            int b = c - a;
            if (tagainiso(a, b)) {
                long long radRtValue = rad((long long)a * b * c);
                if (radRtValue < c) {
                    // printf("rad(a*b*c)=%lld : ", radRtValue);
                    // printf("%d %d %d\n", a, b, c);
                    printf("%d\t%d\t%d\t%lld\n", a, b, c, radRtValue);
                }
            }
        }
    }
    // printf("%lld\n", rad(25 * 40 * 65));
    return 0;
}
// 65000 : 1
// 32500 : 2
// 16250
// 8125 : 2
// 1625 : 10
// 325
// 65
// 13 : 10