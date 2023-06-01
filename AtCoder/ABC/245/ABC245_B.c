//2022/05/30 21:40
//2022/05/30 21:52 AC.
#include <stdio.h>
int main(void){
    int N, arr[2001] = {0}, tmp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        arr[tmp] = 1;
    }
    for (int i = 0; i <= N; i++) {
        //printf("%d : %d\n", i, arr[i]);
        if (!arr[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}