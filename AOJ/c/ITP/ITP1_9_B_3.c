#include <stdio.h>
//#include <string.h>
int main(void){
    char cards_1[201] = {0}, cards_2[201] = {0};
    int m, tmp, size;

    while (scanf("%s", cards_1), cards_1[0] != '-') {

        //字数カウント strlen()
        for (size = 0; cards_1[size] != '\0'; size++) {
        }

        //シャッフル回数の入力と簡易化
        int h = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &tmp);
            h += tmp;
        }
        h = h % size; //0 <= h <= size

        //並べ替え cards_1 -> cards_2
        for (int i = 0; i < size; i++) {
            cards_2[i] = cards_1[(i + h) % size];
        }

        //出力
        for (int i = 0; i < size; i++) {
            printf("%c", cards_2[i]);
        }
        putchar('\n');
    }

    return 0;
}