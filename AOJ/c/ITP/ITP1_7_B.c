#include <stdio.h>
int main(void){
    int n, x;
    while (scanf("%d %d", &n, &x), n + x) {
        int a = 1, b = 2, c = 3, count = 0;
        for (int a = 1; a <= n - 2; a++) {
            for (int b = a + 1; b <= n - 1; b++) {
                for (int c = b + 1; c <= n; c++) {
                    if (a + b + c == x) {
                        count++;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}