#include <stdio.h>
int main(void){
    int n, card[1000][2];
    //0じゃない人見つける
    int i = 0;
    for (; i < n; i++) {
        if (card[i][0] != 0) {
            fcard = card[i][0];
            card[i][0] = card[i][1];
            card[i][1] = 0;
            break;
        }
    }
    
}