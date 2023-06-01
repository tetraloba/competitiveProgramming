//2022/06/05  8:01
//2022/06/05  8:11 AC.
#include <stdio.h>
int main(void){
    int N, tmp, Q[200000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        Q[tmp - 1] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        printf("%d", Q[i]);
        if (i < N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    return 0;
}