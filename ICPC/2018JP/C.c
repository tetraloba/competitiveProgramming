//2022/07/07 23:49
//
#include <stdio.h>
#include <math.h>
int main(void){
    long long int N;
    scanf("%lld", &N);
    for (long long int i = 1; i <= N; i++) {
        long long int tmp = i * (i - 1) + 2 * N;
        for (long long int n = (int)pow(tmp, 0.5) - 3; n <= N; n++) {
            if (tmp == n * (n - 1)) {
                printf("%lld %lld\n", i, i);
                return 0;
            }
        }
        // for (long long int j = i; j <= N; j++) {
        //     if ((i + j) * (j - i + 1) / 2 == N) {
        //         printf("%lld %lld\n", i, j - i + 1);
        //         return 0;
        //     }
        // }
    }
    return 0;
}