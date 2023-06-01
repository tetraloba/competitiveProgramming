//2022/07/18 00:53:51
//2022/07/18 01:07:16 AC. なにこれ・・・
#include <stdio.h>
int pow(int, int);
int main(void){
    char S[3], T[3]; //文字の配列(not 文字列)
    scanf("%c %c %c %c %c %c", &S[0], &S[1], &S[2], &T[0], &T[1], &T[2]);
    int num = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (S[i] == T[j]) {
                num += (i + 1) * pow(10, 2 - j);
                break;
            }
        }
    }
    // printf("%d\n", num);
    if (num == 123 || num == 231 || num == 312) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
int pow(int a, int b){
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
// 123 213 123
// 132 123 x
// 213 123 x
// 231 132 123
// 312 132 123
// 321 123 x