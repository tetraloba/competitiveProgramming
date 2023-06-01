//2022-08-04 07:48:26
//2022-08-04 08:01:27 AC.
#include <stdio.h>
int min(int, int);
int main(void){
    int N, K[100000 - 1], L[100000];
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d", &K[i]);
    }
    L[0] = K[0];
    for (int i = 1; i < N - 1; i++) {
        L[i] = min(K[i - 1], K[i]);
    }
    L[N - 1] = K[N - 2];
    for (int i = 0; i < N; i++) {
        printf("%d", L[i]);
        if (i < N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    return 0;
}
int min(int a, int b){
    if (a < b) {
        return a;
    }
    return b;
}