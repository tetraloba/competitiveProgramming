#include <stdio.h>
int main(void){
    int n, k;

    scanf("%d", &n);
    k = n;
    printf("%d:", n);
    int i = 2;
    while (i * i <= k) {
        if (k % i == 0) {
            printf(" %d", i);
            k /= i;
        } else {
            i++;
        }
    }
    printf(" %d\n", k);

    return 0;
}