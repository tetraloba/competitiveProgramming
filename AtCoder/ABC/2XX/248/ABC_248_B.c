//2022/05/29 22:12
//2022/05/29 22:22 AC 有効桁数で手間取った。連続提出制限に引っかかるなどした。long long int
#include <stdio.h>
int main(void){
    long long int A, B; 
    int K, count = 0;
    scanf("%lld %lld %d", &A, &B, &K);
    while (A < B) {
        A *= K;
        count++;
    }
    printf("%d\n", count);
    return 0;
}