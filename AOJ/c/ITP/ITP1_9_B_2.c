#include <stdio.h>
int main(void){
    char cards[201] = {0};
    int m, h = 0, tmp, size;
    scanf("%s", cards);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &tmp);
        h += tmp;
    }
    for (size = 0; cards[size] != '\0'; size++) {
        printf("1:%c ", cards[size]);
    }
    h = h % size; //0 <= h <= size
    tmp = cards[0];
    for (int i = 0; i < size; i++) {
        if ((i + h) % size) {
            cards[i] = cards[(i + h) % size];
        } else {
            cards[i] = tmp;
        }
    }
    for (int i = 0; i < size; i++) {
        printf("2:%c ", cards[i]);
    }
    printf("size=%d", size);
    printf("\n%d\n", h);
    return 0;
}