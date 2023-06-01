//2022/07/06 17:10
//2022/07/06 17:35 AC.
#include <stdio.h>
int strComp(char*, char*); //一致で1, 不一致で0
int main(void){
    int N;
    char s[100][11] = {0}, t[100][11] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i]);
        scanf("%s", t[i]);
    }
    for (int i = 0; i < N; i++) {
        int judgeS = 0, judgeT = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (strComp(s[i], s[j]) || strComp(s[i], t[j])) {
                // printf("%s : %s, %s\n", s[i], s[j], t[j]);
                judgeS++;
            }
            if (strComp(t[i], s[j]) || strComp(t[i], t[j])) {
                // printf("%s : %s, %s\n", t[i], s[j], t[j]);
                judgeT++;
            }
        }
        if (judgeS != 0 && judgeT != 0) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
int strComp(char *s1, char *s2){
    while (*s1 || *s2) {
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    return 1;
}
//ある人の姓・名のどちらかが、他の人の姓・名リストと一致しなければYes.