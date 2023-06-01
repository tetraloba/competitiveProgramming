//2022/07/17 23:39:54
//2022/07/17 23:47:41 TLE
#include <stdio.h>
int strcmp(char*, char*);
int unique(char S[][11], int);
int main(void){
    int N, T[100000];
    char S[100000][11];
    scanf("%d", &N);
    int max = -1, ans;
    for (int i = 0; i < N; i++) {
        scanf("%s %d", S[i], &T[i]);
        if (max < T[i] && unique(S, i)) {
            max = T[i];
            ans = i + 1;
        } 
    }
    printf("%d\n", ans);
    return 0;
}
int unique(char S[][11], int N){
    for (int i = 0; i < N; i++) {
        if (!strcmp(S[i], S[N])) {
            return 0;
        }
    }
    return 1;
}
int strcmp(char *S1, char *S2){
    while (*S1) {
        if (*S1++ != *S2++) {
            return 1;
        }
    }
    if (*S2) {
        return 1;
    }
    return 0;
}