//2022/05/29 21:19
//2022/05/29 21:57 gave up. アルゴリズムについて根本的な考え違いをしている。
#include <stdio.h>
int func_unique(int N, char str1[][11], char str2[11]); //N個の文字列を持つstr1に対して文字列str2がuniqueであるか判定
int main(void){
    int N;
    char s[100][11], t[100][11], a[100][11];
    scanf("%d", &N);
    int unique = 1;
    for (int i = 0; i < N; i++) {
        scanf(" %s", s[i]);
        scanf(" %s", t[i]);
        if ((func_unique(i, s, s[i]) == 0 || func_unique(i, t, s[i]) == 0) && (func_unique(i, t, t[i]) == 0 || func_unique(i, s, t[i]) == 0) ) {
            unique = 0;
        }
    }
    if (unique) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
int func_unique(int N, char str1[][11], char str2[11]){
    for (int i = 0; i < N; i++) {
        int unique = 0;
        for (int j = 0; str1[i][j]; j++) {
            if (str1[i][j] != str2[j]) {
                unique = 1;
                break;
            }
        }
        printf("%c : %c == %d\n", str1[i][1], str2[1], unique);
        if (unique == 0) {
            return 0; //common
        }
    }
    return 1; //unique
}