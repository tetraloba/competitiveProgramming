//2022/06/18 21:02
//2022/06/18 21:11
#include <stdio.h>
int main(void){
    int P = 0, A, N, arr[4] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        arr[0] = 1;
        for (int j = 3; 0 <= j; j--) {
            if (arr[j] == 1) {
                arr[j] = 0;
                if (4 <= j + A) {
                    P++;
                } else {
                    arr[j + A] = 1;
                }
            }
        }
    }
    printf("%d\n", P);
    return 0;
}