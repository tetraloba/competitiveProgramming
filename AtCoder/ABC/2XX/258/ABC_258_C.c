//2022/07/17 23:22:20
//2022/07/17 23:38:55 AC.
#include <stdio.h>
int main(void){
    int N, Q;
    char S[500000];
    scanf("%d %d %s", &N, &Q, S);
    int head = 0;
    for (int i = 0; i < Q; i++) {
        int query, x;
        scanf("%d %d", &query, &x);
        if (query == 1) {
            head = (head + x) % N;
        } else {
            printf("%c\n", S[(x + N - head - 1) % N]);
        }
    }
    return 0;
}