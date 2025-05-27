//2022-07-24 10:52:16
//2022-07-24 11:02:02 AC.
#include <stdio.h>
int main(void){
    int A, B, C, X;
    scanf("%d %d %d %d", &A, &B, &C, &X);
    double ans;
    if (X <= A) {
        ans = 1;
    } else if (X <= B) {
        ans = (double)C / (B - A);
    } else {
        ans = 0;
    }
    printf("%f\n", ans);
    return 0;
}