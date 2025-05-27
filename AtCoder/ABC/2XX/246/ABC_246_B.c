//2022/05/30 21:19
//2022/05/30 21:39 AC
#include <stdio.h>
#include <math.h>
int main(void){
    int A, B;
    scanf("%d %d", &A, &B);
    double K2 = pow(A, 2) + pow(B, 2);
    printf("%f %f\n", pow(1 - pow(B, 2) / K2, 0.5), pow(1 - pow(A, 2) / K2, 0.5));
    return 0;
}