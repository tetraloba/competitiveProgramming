// 2023/06/24 18:52:52
// 2023/06/24 18:57:20
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    char *S = malloc(sizeof(char) * N);
    scanf("%s", S);
    switch (S[K - 1]) {
        case 'A':
            S[K - 1] = 'a';
            break;
        case 'B':
            S[K - 1] = 'b';
            break;
        case 'C':
            S[K - 1] = 'c';
            break;
    }
    printf("%s\n", S);
    
    free(S);
    return 0;
}
