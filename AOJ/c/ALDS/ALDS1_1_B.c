#include <stdio.h>
int GCD(int x, int y){
    static int gcd;
    if (x >= y) {
        if (x % y == 0) {
            return y;
        }
        gcd = GCD(y, x % y);
    }
    return gcd;
}
int main(void){
    int x, y, tmp;
    scanf("%d %d", &x, &y);
    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    printf("%d\n", GCD(x, y));
    return 0;
}