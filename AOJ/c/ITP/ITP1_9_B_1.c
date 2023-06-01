#include <stdio.h>
int main(void){
    char cards_1[201] = {0}, cards_2[201] = {0};
    int m, h = 0, tmp, size;
    scanf("%s", cards_1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        h += tmp;
    }
    for (size = 0; cards_1[size] != '\0'; size++) {
        printf("1:%c ", cards_1[size]);
    }
    h = h % size; //0 <= h <= size
    for (int i = 0; i < size; i++) {
        cards_2[i] = cards_1[(i + h) % size];
    }
    /*cards_2[1 - 1] = (1 + h - 1) % 5 + 1;
    cards_2[2 - 1] = (2 + h - 1) % 5 + 1;
    cards_2[1 - 1] = cards_1[(1 + h - 1) % 5]
    cards_2[i] = cards_1[(i + h) % 5]*/
    for (int i = 0; i < size; i++) {
        printf("2:%c ", cards_2[i]);
    }
    printf("size=%d", size);
    printf("\n%d\n", h);
    return 0;
}