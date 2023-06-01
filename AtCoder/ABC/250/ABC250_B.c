//2022/07/03 16:25
//2022/07/03 16:45 AC.
#include <stdio.h>
int main(void){
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    int flag1 = 1, flag2 = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A; j++) {
            flag2 = flag1;
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < B; l++) {
                    if (flag2) {
                        putchar('.');
                    } else {
                        putchar('#');
                    }
                }
                flag2 = !flag2;
            }
            putchar('\n');
        }
        flag1 = !flag1;
    }
    return 0;
}