//2022-07-24 11:04:30
//2022-07-24 11:08:17 AC.
#include <stdio.h>
int main(void){
    char S[200001];
    int chr[26] = {0};
    scanf("%s", S);
    char *p = S;
    while (*p) {
        chr[*p++ - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < chr[i]; j++) {
            putchar('a' + i);
        }
    }
    putchar('\n');
    return 0;
}