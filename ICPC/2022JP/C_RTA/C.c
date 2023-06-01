#include <stdio.h>
#include <limits.h>
int main(void){
    long long int n, m;
    while (1) {
        long long int p;
        long long int max = LLONG_MIN;
        scanf("%lld %lld", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        if (n == 0) {
            max = - m * m;
        } else if (m == 0) {
            max = n * n;
        } else if (m == 1) {
            max = n * n - 1;
        } else {
            int i = 1, j = 2;
            for (; i <= n && j <= m; i++, j++) {
                p = (i - 1) + (n - i + 1) * (n - i + 1) - ((m / j) * (m / j) * (j - m % j) + (m / j + 1) * (m / j + 1) * (m % j));
                // printf("%lld %lld %lld\n", (n - i + 1), (n - i + 1) * (n - i + 1), ((m / j) * (m / j) * (j - m % j) + (m / j + 1) * (m / j + 1) * (m % j)));
                if (max < p) {
                    max = p;
                }
                // printf("%d %d %lld\n", i, j, p);
            }
        }
        printf("%lld\n", max);
    }
    return 0;
}