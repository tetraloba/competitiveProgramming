#include <stdio.h>
int main(void){
    int N, X;
    char S[2601];
    scanf("%d %d", &N, &X);
    int k = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < N; j++) {
            S[k++] = 'A' + i;
        }
    }
    /* debug用 */
    // for (int i = 0; S[i] != 0; i++) {
    //     putchar(S[i]);
    // }
    putchar(S[X - 1]);
    putchar('\n');
    return 0;
}