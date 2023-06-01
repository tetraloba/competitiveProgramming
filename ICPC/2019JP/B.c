//2022/07/01 19:18
//2022/07/01 19:48 AC.
#include <stdio.h>
int dif(int, int);
int main(void){
    int h, w, cp[2], push; //cp:現在地, push:ボタン押下数
    char key[51][51], str[1001];
    while (1) {
        cp[0] = 0;
        cp[1] = 0;
        push = 0;
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf(" %c", &key[i][j]);
            }
        }
        scanf("%s", str);
        int flag = 0;
        for (int i = 0; str[i]; i++) {
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < w; k++) {
                    if (str[i] == key[j][k]) {
                        push += dif(j, cp[0]) +dif(k, cp[1]) + 1; //+1はOK押下
                        cp[0] = j;
                        cp[1] = k;
                        int flag = 1;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }
        printf("%d\n", push);
    }
    return 0;
}
int dif(int a, int b){
    if (a < b) {
        return b - a;
    }
    return a - b;
}