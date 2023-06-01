//2022/07/09 20:34
//2022/07/09 20:38 WA
#include <stdio.h>
int main(void){
    int A, B, C, X;
    double ans;
    scanf("%d %d %d %d", &A, &B, &C, &X);
    if (X < A) {
        ans = 1.0;
    } else if (X < B) {
        ans = (double)C / (B - A);
    } else {
        ans = 0;
    }
    printf("%f\n", ans);
    return 0;
}