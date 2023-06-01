#include <stdio.h>
int bubbleSort(char s[][3], int);
int selectionSort(char s[][3], int);
void arrCopy(char s1[][3], char s2[][3], int);
int stable(char ans[][3], char original[][3], int);
int main(void){
    int N;
    char original[36][3], ans1[36][3], ans2[36][3];
    //入力
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s", original[i]);
    }
    //配列のコピーとソート
    arrCopy(original, ans1, N);
    arrCopy(ans1, ans2, N);
    bubbleSort(ans1, N);
    selectionSort(ans2, N);
    //bubbleSortの出力と判定
    for (int i = 0; i < N; i++) {
        printf("%s", ans1[i]);
        if (i != N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    if (stable(ans1, original, N)) {
        puts("Stable");
    } else {
        puts("Not stable");
    }
    //slectionSortの出力と判定
    for (int i = 0; i < N; i++) {
        printf("%s", ans2[i]);
        if (i != N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    if (stable(ans2, original , N)) {
        puts("Stable");
    } else {
        puts("Not stable");
    }
    return 0;
}
void arrCopy(char s1[][3], char s2[][3], int n){
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (s1[i][j]) {
            s2[i][j] = s1[i][j];
            j++;
        }
        s2[i][j] = 0;
    }
    return;
}
int stable(char ans[][3], char original[][3], int n) {
    int continuous, flag; //連続する数continuousと、不適切な比較対象をスキップするためのflag
    for (int i = 0; i < n - 1; i++) {
        if (ans[i][1] == ans[i + 1][1]) {
            if (i == 0 || ans[i - 1][1] != ans[i][1]) {
                continuous = 0;
            }
            flag = continuous; //連続回数continuous分比較対象をずらす
            for (int j = 0; j < n; j++) {
                if (ans[i][1] == original[j][1]) {
                    if (flag) {
                        flag--;
                        continue;
                    }
                    continuous++;
                    if (ans[i][0] == original[j][0]) {
                        break;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
/*これバブルソートじゃないわ
int bubbleSort(char s[][3], int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j][1] < s[i][1]) {
                char tmp = s[i][0];
                s[i][0] = s[j][0];
                s[j][0] = tmp;
                tmp = s[i][1];
                s[i][1] = s[j][1];
                s[j][1] = tmp;
                count++;
            }
        }
    }
    return count;
}*/
int bubbleSort(char s[][3], int n){
    int count = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1][1] < s[i][1]) {
                char tmp = s[i][0];
                s[i][0] = s[i + 1][0];
                s[i + 1][0] = tmp;
                tmp = s[i][1];
                s[i][1] = s[i + 1][1];
                s[i + 1][1] = tmp;
                count++;
                flag = 1;
            }
        }
    }
    return count;
}
int selectionSort(char s[][3], int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j][1] < s[minj][1]) {
                minj = j;
            }
        }
        if (minj != i) {
            char tmp = s[i][0];
            s[i][0] = s[minj][0];
            s[minj][0] = tmp;
            tmp = s[i][1];
            s[i][1] = s[minj][1];
            s[minj][1] = tmp;
            count++;
        }
    }
    return count;
}