#include <stdio.h>
int main(void){
    int dice[6] = {1, 2, 3, 4, 5, 6}, n = 0/*命令の数*/;
    char controle[101] = {0};
    for (int i = 0; i < 6; i++) {
        scanf("%d", &dice[i]);
    }
    scanf("%s", controle);
    for (int i = 0; i < 101; i++) {
        if (controle[i] == '\0') {
            break;
        }
        n++;
    }
    int tmp;
    for (int i = 0; i < n; i++) {
        switch (controle[i]) {
          case 'W' :
            tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
            break;
          case 'E' :
            tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
            break;
          case 'S' :
            tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
            break;
          case 'N' :
            tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = tmp;
            break;
        }
    }
    printf("%d\n", dice[0]);
    return 0;
}