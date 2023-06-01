//
//2022/06/11 21:02
#include <stdio.h>
int main(void){
    int A[2][2], R, C;
    scanf("%d %d %d %d %d %d", &R, &C, &A[0][0], &A[0][1], &A[1][0], &A[1][1]);
    printf("%d\n", A[R-1][C-1]);
    return 0;
}