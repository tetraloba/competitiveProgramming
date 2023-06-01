#include <stdio.h>
int main(void){
    int N, A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int flag = 1, count = 0;
    while (flag) {
        flag = 0;
        for (int j = 0; j < N - 1; j++) {
            if (A[j + 1] < A[j]) {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    printf("%d\n", count);
    return 0;
}