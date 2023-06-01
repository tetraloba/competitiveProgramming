#include <stdio.h>


int main(void) {
    int r, c, n, temp1, hyo[20] = {0};
    int q = 1;
    
    scanf("%d %d", &r, &c);
    int x = 0;    //表の配列の要素指定
    for (int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &n);
            hyo[x++] = n;
        }
        hyo[x++] = 0;
    }
    

    printf("\n");

    //各行の和
    int p = 0;
    for (int i = 1; i <= r * c; i++) {
        if ( i % c == 0) {
            temp1 = i - c + p;
            for (int j = 0; j < c; j++) {
                hyo[i + p] += hyo[temp1++];
            }
            p++;
        }
    }

    //r+1行目の処理。各列の和。
    for (int i = 0; i <= c; i++) {
        for (int j = i; j < r * (c + 1); j += c + 1) {
            hyo[x] += hyo[j];
        }
        x++;
    }
    //出力
    for (int i = 0; i < (r + 1) * (c + 1); i++) {
        if ( (i + 1) % (c + 1) ) {
            printf("%d ", hyo[i]);
        } else {
            printf("%d\n", hyo[i]);
        }
        
    }
    return 0;
}