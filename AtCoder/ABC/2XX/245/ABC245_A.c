//2022/05/31 12:22 on FireHD
//2022/05/31 12:32 AC on PC
#include <stdio.h>
int main(void){
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    if (A < C || (A == C && B <= D)) {
        puts("Takahashi");
    } else {
        puts("Aoki");
    }
    return 0;
}