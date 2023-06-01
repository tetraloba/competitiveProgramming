//2022/07/08 16:31
//
#include <stdio.h>
int main(void){
    int n; // 2 <= n <= 1000
    int card[1000][2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        if (c1 == c2) {
            card[i][0] = 0;
            card[i][1] = 0;
        }else if (c1 < c2) {
            card[i][0] = c1;
            card[i][1] = c2;
        } else {
            card[i][0] = c2;
            card[i][1] = c1;
        }
    }
    //debug
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", card[i][0], card[i][1]);
    }
    int fcard, i = 0;
    i = findP(i, n, card);
    if (i == -1) {
        puts("0");
        // break;
        return 0;
    }
    fcard = card[i][0];
    card[i][0] = card[i][1];
    card[i][1] = 0;
    i++;
    int flag = 2;
    while (flag) {
        for (; i < n; i++) {
            if (fcard == card[i][0]) {
                card[i][0] = 0;
                fcard = card[i][1]; //card[i][1] == 0なら？ -> iを維持したまま最初に戻る
                card[i][1] = 0;
                flag++;
            } else if (fcard == card[i][1]) {
                card[i][1] = 0;
                fcard = card[i][0];
                card[i][0] = 0;
                flag++;
            } else if (card[i][1] < fcard) {
                int tmp = fcard;
                fcard = card[i][0];
                card[i][0] = card[i][1];
                card[i][1] = tmp;
                flag++;
            } else if (card[i][0] < fcard) {
                int tmp = fcard;
                fcard = card[i][0];
                card[i][0] = tmp;
                flag++;
            }
            count++;
        }
        flag--;
        i = 0;
    }
    int count = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (; i < n; i++) {
            if (fcard == card[i][0]) {
                card[i][0] = card[i][1];
                card[i][1] = 0;
                flag = 1;
                count++;
            } else if (fcard == card[i][1]) {
                card[i][1] = 0;
                flag = 1;
                count++;
            } else if (card[i][1] < fcard) {
                int tmp = fcard;
                fcard = card[i][0];
                card[i + 1][0] = card[i + 1][1];
                card[i + 1][1] = tmp;
            } else if (card[i + 1][0] < fcard) {
                int tmp = fcard;
                fcard = card[i + 1][0];
                card[i + 1][0] = fcard;
            }
        }
        i = 0;
    }
    printf("%d\n", count);
    return 0;
}
int findeP(int i, int n, int card[][2]){
    for (int j = i;j < n; j++) {
        if (card[j][0] != 0) {
            return j;
        }
    }
    for (int j = 0; j < i; j++) {
        if (card[j][0] != 0) {
            return j;
        }
    }
    return -1;
}