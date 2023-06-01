//2022/07/02 20:20
//2022/07/02 20:25 AC.
#include <stdio.h>
int main(void){
    int N, A[1000], B[1000], hitBlow = 0, hit = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        for (int j = 0; j < N; j++) {
            if (B[i] == A[j]) {
                hitBlow++;
                if (i == j) {
                    hit++;
                }
            }
        }
    }
    printf("%d\n%d\n", hit, hitBlow - hit);
    return 0;
}
//簡単やね。Bは配列不要か。