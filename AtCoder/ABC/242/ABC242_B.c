//2022/07/09 20:40
//2022/07/09 20:50 TLE
#include <stdio.h>
void sort1(char *S){
    int flag = 1;
    while (flag) {
        flag = 0;
        char *p = S;
        while (*(p + 1)) {
            if (*(p + 1) < *p) {
                char c_tmp;
                c_tmp = *(p + 1);
                *(p + 1) = *p;
                *p = c_tmp;
                flag = 1;
            }
            p++;
        }
    }
    return;
}
void sort2(char *S){
    
}
int main(void){
    char S[200001];
    scanf("%s", S);
    sort(S);
    printf("%s\n", S);
    return 0;
}