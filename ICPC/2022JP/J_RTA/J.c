//2022/07/08 13:28
//
#include <stdio.h>
int main(void){
    int n, a, max;
    while (1) {
        scanf("%d", &n);
        if (!n) {
            break;
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (max < a) {
                max = a;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}