//2022/07/02 21:00
//2022/07/02 21:01 AC.
#include <stdio.h>
int main(void){
    int K;
    scanf("%d", &K);
    printf("%d:%02d\n", 21 + K / 60, K % 60);
    return 0;
}