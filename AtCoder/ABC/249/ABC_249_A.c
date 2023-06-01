//2022/07/03 16:11
//2022/07/03 16:23
#include <stdio.h>
int main(void){
    int A, B, C, D, E, F, X;
    int takahashi, aoki;
    scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &X);
    takahashi = B * A * (X / (A + C));
    takahashi += X % (A + C) < A ? B * (X % (A + C)) : B * A;
    aoki = E * D * (X / (D + F));
    aoki += X % (D + F) < D ? E * (X % (D + F)) : E * D;
    if (takahashi < aoki) {
        puts("Aoki");
    } else if (takahashi == aoki) {
        puts("Draw");
    } else {
        puts("Takahashi");
    }
    return 0;
}