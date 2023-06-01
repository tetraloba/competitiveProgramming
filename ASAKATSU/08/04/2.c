//2022-08-04 07:38:51
//2022-08-04 07:48:05 AC.
#include <stdio.h>
#include <string.h>
int main(void){
    int N, P, max = 0, sum = 0;
    char S[21], maxName[21];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d", S, &P);
        sum += P;
        if (max < P) {
            max = P;
            strcpy(maxName, S);
        }
    }
    // printf("%d %d %s\n", max, sum, maxName); //debug
    if (max * 2 <= sum) {
        puts("atcoder");
    } else {
        printf("%s\n", maxName);
    }
    return 0;
}