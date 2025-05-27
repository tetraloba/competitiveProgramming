//2022-07-23 21:17:18
//2022-07-23 21:25:03 AC.
#include <stdio.h>
int main(void){
    int N, A[1000][1000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char tmp;
            scanf(" %c", &tmp);
            if (i == j) {
                continue;
            }
            if (tmp == 'W') {
                A[i][j] = 2;
            } else if (tmp == 'L') {
                A[i][j] = 0;
            } else {
                A[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i][j] + A[j][i] != 2) {
                puts("incorrect");
                return 0;
            }
        }
    }
    puts("correct");
    return 0;
}