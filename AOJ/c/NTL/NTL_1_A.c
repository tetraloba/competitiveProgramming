#include <stdio.h>
#include <math.h>
int main(void){
    int n, k, l;

    scanf("%d", &n);
    k = n;
    printf("%d:", n);
    l = 1;
    int i = 2;
    while (k > 1) {
        if (k % i == 0) {
            printf(" %d", i);
            k /= i;
            l = 0;
            continue;
        }
        if (l && i > sqrt(n)) {
            printf(" %d", n);
            break;
        }
        i++;
    }
    putchar('\n');

    return 0;
}

/*
    for (int i = 2; k > 1; i++) {
        if (k % i == 0) {
            printf(" %d", i);
            k /= i;
            continue;
        }
    }
*/

/*
    int n, k;

    scanf("%d", &n);
    k = n;
    printf("%d:", n);
    int i = 2;
    while (k > 1) {
        if (k % i == 0) {
            printf(" %d", i);
            k /= i;
            continue;
        }
        i++;
    }
    putchar('\n');

    return 0;
*/

/*
int main(void){
    int n, k, l;

    scanf("%d", &n);
    k = n;
    printf("%d:", n);
    l = 1;
    int i = 2;
    while (k > 1) {
        if (k % i == 0) {
            printf(" %d", i);
            k /= i;
            l = 0;
            continue;
        }
        if (l && i > n / 2) {
            printf(" %d", n);
            break;
        }
        i++;
    }
    putchar('\n');

    return 0;
*/