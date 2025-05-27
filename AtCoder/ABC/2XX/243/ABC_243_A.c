#include <stdio.h>
int main(void){
    int V, A, B, C;
    scanf("%d %d %d %d", &V, &A, &B, &C);
    V %= A + B + C;
    if (V < A) {
        puts("F");
    } else if (V - A < B) {
        puts("M");
    } else {
        puts("T");
    }
    return 0;
}