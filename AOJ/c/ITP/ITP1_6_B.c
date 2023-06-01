#include <stdio.h>
int main(void){
    int num;    //枚数
    char suit;  //絵柄
    int rank;   //数字

    int S[13], H[13], C[13], D[13];
    for (int i = 0; i < 13; i++) {
        S[i] = i + 1;
    }
    for (int i = 0; i < 13; i++) {
        H[i] = i + 1;
    }
    for (int i = 0; i < 13; i++) {
        C[i] = i + 1;
    }
    for (int i = 0; i < 13; i++) {
        D[i] = i + 1;
    }

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf(" %c %d", &suit, &rank);
        if (suit == 'S') {
            S[rank - 1] = 0;
        } else if (suit == 'H') {
            H[rank - 1] = 0;
        } else if (suit == 'C') {
            C[rank - 1] = 0;
        } else {
            D[rank - 1] = 0;
        }
    }

    for (int i = 0; i < 13; i++) {
        if (S[i] != 0) {
            printf("S %d\n",S[i]);
        }
    }
    for (int i = 0; i < 13; i++) {
        if (H[i] != 0) {
            printf("H %d\n",H[i]);
        }
    }
    for (int i = 0; i < 13; i++) {
        if (C[i] != 0) {
            printf("C %d\n",C[i]);
        }
    }
    for (int i = 0; i < 13; i++) {
        if (D[i] != 0) {
            printf("D %d\n",D[i]);
        }
    }

    return 0;
}