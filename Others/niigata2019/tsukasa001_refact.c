#include <stdio.h>
#include <math.h>

void swap(int *a, int *b){
    int tmp = *a;
    int *a = *b;
    int *b = tmp;
}

int cmp(int a, int b){
    ;
}

int main()
{
    int n[4];
    int s = 0;
    int n_idx[4];
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
            if (n[j]/10 && n[j+1]/10 && n[j] < n[j+1]) { // 両方2桁 なら 単純比較
                swap(n[j + 1], n[j])
            }else if (n[j]/10==0 && n[j+1]/10==0 && n[j] < n[j+1]) { // 両方1桁 なら 単純比較
                swap(n[j + 1], n[j])
            }else if (n[j]/10==0 && n[j+1]/10 && n[j] * 11 < n[j+1]) { // 1桁:2桁 なら
                swap(n[j + 1], n[j])
            }else if (n[j]/10 && n[j+1]/10==0 && n[j] < n[j+1] * 11) {
                swap(n[j + 1], n[j])
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d", n[i]);
    }
    putchar('\n');
}