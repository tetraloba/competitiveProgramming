#include <stdio.h>
int main(void){
    int m, f, r;
    while (scanf("%d %d %d", &m, &f, &r), m + f + r != -3) {
        if (m == -1 || f == -1) {
            puts("F");
        } else if (m + f >= 80) {
            puts("A");
        } else if (m + f >= 65) {
            puts("B");
        } else if (m + f >= 50 || r >= 50) {
            puts("C");
        } else if (m + f >= 30) {
            puts("D");
        } else {
            puts("F");
        }
    }

    return 0;
}