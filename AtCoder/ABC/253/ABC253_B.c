#include <stdio.h>
int func_dif(int, int);
int main(void){
    int H, W, s1i, s1j, s2i, s2j, swt = 0;
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c = 0;
            while (c != '-' && c !='o') {
                c = getchar();
            }
            if (c == 'o' && swt == 0) {
                s1i = i;
                s1j = j;
                //printf("s1i = %d\n", s1i);
                //printf("s1j = %d\n", s1j);
                swt = 1;
            } else if (c == 'o') {
                s2i = i;
                s2j = j;
                //printf("s2i = %d\n", s2i);
                //printf("s2j = %d\n", s2j);
                break;
            }
        }
    }
    printf("%d\n", s2i - s1i + func_dif(s2j, s1j));
    return 0;
}

int func_dif(int a, int b){
    if (a < b) {
        return b - a;
    } else {
        return a - b;
    }
}