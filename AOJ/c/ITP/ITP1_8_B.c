#include <stdio.h>
int main(void){
    int n, sum;
    while (scanf("%d", &n), n) {
        sum = 0;
        while (n) {
            sum += n % 10;
            n = n / 10;
        }
        printf("%d\n", sum);
    }
    return 0;
}