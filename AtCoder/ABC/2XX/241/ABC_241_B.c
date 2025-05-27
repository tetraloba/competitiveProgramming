#include <stdio.h>
int main(void){
    int N, M, A[1000], B;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        int flag = 1;
        scanf("%d", &B);
        for (int j = 0; j < N; j++) {
            // printf("%d : %d\n", A[j], B);
            if (B == A[j]) {
                A[j] = 0;
                flag = 0;
                break;
            }
        }
        if (flag) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}