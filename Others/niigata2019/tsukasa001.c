#include <stdio.h>
#include <math.h>

int main()
{
    int n[4];
    int s = 0;
    int n_idx[4];
    // printf("1~99の範囲の整数を入力してください\n");
    while (s != 4) {
        scanf("%d", &n[s]);
        if (n[s] >= 1 && n[s] <= 99) {
            s++;
        } else {
            printf("miss\n");
        }
    }

    int tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4-i-1; j++) {
            if (n[j]/10 && n[j+1]/10 && n[j] < n[j+1]) {
                tmp = n[j+1];
                n[j+1] = n[j];
                n[j] = tmp;
            }else if (n[j]/10==0 && n[j+1]/10==0 && n[j] < n[j+1]) {
                tmp = n[j+1];
                n[j+1] = n[j];
                n[j] = tmp;
            }else if (n[j]/10==0 && n[j+1]/10 && n[j] * 11 < n[j+1]) {
                tmp = n[j+1];
                n[j+1] = n[j];
                n[j] = tmp;
            }else if (n[j]/10 && n[j+1]/10==0 && n[j] < n[j+1] * 11) {
                tmp = n[j+1];
                n[j+1] = n[j];
                n[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d", n[i]);
    }
    putchar('\n');
}