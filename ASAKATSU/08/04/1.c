#include <stdio.h>
int pow(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int main(void){
    int A, B, C, K;
    scanf("%d %d %d %d", &A, &B, &C, &K);
    int *max;
    if (A < B) {
        if (B < C) {
            max = &C;
        } else {
            max = &B;
        }
    } else {
        if (C < A) {
            max = &A;
        } else {
            max = &C;
        }
    }
    printf("%d\n", A + B + C - *max + *max * pow(2, K));
    return 0;
}
// ABC1
// ACB2
// BAC4
// BCA3
// CAB2
// CBA3