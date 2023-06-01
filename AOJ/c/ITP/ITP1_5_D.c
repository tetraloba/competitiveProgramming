#include <stdio.h>
int main(void){
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        //3の倍数かの判定
        if (i % 3 == 0) {
            printf(" %d", i);
        } else {
            //3が付くかの判定
            int x = i;
            while (x) {
                if (x % 10 == 3) {
                    printf(" %d", i);
                    break;
                }
                x /= 10;
            }
        }
    }
    putchar('\n');
    
    return 0;
}