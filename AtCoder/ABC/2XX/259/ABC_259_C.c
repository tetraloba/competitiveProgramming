//2022/07/09 21:12
//2022/07/09 21:30 WA RE
//2022/07/09 21:57 AC.

#include <stdio.h>
int main(void){
    char S[200001], T[200001];
    scanf("%s %s", S, T);

    int flag = 1;
    int i = 0, j = 0;
    while (S[i]) {
        if (S[i] != T[j]) {
            // printf("%d%c : %d%c\n", i, S[i], j, T[j]);
            flag = 0;
            break;
        }
        if (S[i] == S[i + 1] && T[j] == T[j + 1]) { //文字が連続している場合
            // printf("%c : %c same1\n", S[i], T[j]);
            int count1 = 0, count2 = 0;
            while (S[i] == S[i + 1]) {
                i++;
                count1++;
            }
            while (T[j] == T[j + 1]) {
                j++;
                count2++;
            }
            if (count2 < count1) {
                flag = 0;
                break;
            }
            // printf("%d%c : %d%c same2\n", i, S[i], j, T[j]);
        }
        i++;
        j++;
        // printf("%d%c : %d%c same or dif\n", i, S[i], j, T[j]);
    }
    // printf("i:%d j:%d f:%d\n", i, j, flag);
    if (flag && S[i] == 0 && T[j] == 0) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}