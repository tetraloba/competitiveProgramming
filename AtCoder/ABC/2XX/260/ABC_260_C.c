//2022/07/17 21:34:03
//2022/07/17 21:46:49 AC.
#include <stdio.h>
int main(void){
    int N, X, Y;
    long long int R[10] = {0}, B[10] = {0};
    scanf("%d %d %d", &N, &X, &Y);
    R[N - 1] = 1;
    for (int i = N - 1; 0 < i; i--) {
        if (R[i]) {
            R[i - 1] += R[i];
            B[i] += R[i] * X;
            R[i] = 0;
        }
        if (B[i]) {
            R[i - 1] += B[i];
            B[i - 1] += B[i] * Y;
            B[i] = 0;
        }
    }
    printf("%lld\n", B[0]);
    return 0;
}