//2022/06/25 21:00
//2022/06/25 21:02 WA
#include <stdio.h>
int up(int, int);
int main(void){
    int N, X;
    scanf("%d %d", &N, &X);
    putchar((X / N + up(X, N)) % 26 + 'A' - 1);
    putchar('\n');
    return 0;
}
int up(int a, int b){
    if (a % b) {
        return 1;
    }
    return 0;
}
//3 13
//AAA BBB CCC DDD E