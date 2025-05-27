//2022/07/09 21:07
//2022/07/09 21:39 AC.
#define PI 3.14159265358979323846264338
#include <stdio.h>
#include <math.h>
int main(void){
    int a, b, c;
    double x, y;
    scanf("%d %d %d", &a, &b, &c);
    x = a * cos(c * PI / 180) - b * sin(c * PI / 180);
    y = a * sin(c * PI / 180) + b * cos(c * PI / 180);
    printf("%f %f\n", x, y);
    return 0;
}