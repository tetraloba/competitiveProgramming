#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979
int main(void){
    int a, b, C;
    double S, L, h;
    scanf("%d %d %d", &a, &b, &C);
    printf("%f\n%f\n%f\n", a * b * sin(C * PI / 180) / 2, a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C * PI / 180)), b * sin(C * PI / 180));
    return 0;
}