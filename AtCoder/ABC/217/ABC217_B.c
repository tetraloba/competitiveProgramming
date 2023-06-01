//2022/06/05  7:50
//2022/06/05  8:00 AC.
#include <stdio.h>
int main(void){
    char contest[4] = {'B', 'R', 'G', 'H'}, S[3][4];
    for (int i = 0; i < 3; i++) {
        scanf(" %s", S[i]);
    }
    for (int i = 0; i < 4; i++) {
        int check = 0;
        for (int j = 0; j < 3; j++) {
            if (contest[i] == S[j][1]) {
                check = 1;
                break;
            }
        }
        if (!check) {
            printf("A%cC\n", contest[i]);
            break;
        }
    }
    return 0;
}