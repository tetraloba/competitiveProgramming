//2022/07/01 19:51
//
#include <stdio.h>
int unique(int*, int);
int main(void){
    int m, n, p; //1<=m<=100, 0<=n<=1000, 1<=p<=m
    int career[100], log[1000][2];
    for (int i = 0; i < 100; i++) {
        career[i] = 0;
    }
    //入力 ログは配列logに格納
    scanf("%d %d %d", &m, &n, &p);
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        log[i][0] = tmp1 - 1;
        log[i][1] = tmp2 - 1;
    }
    career[p - 1] = 1;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (!(career[log[i][0]] == 1 && career[log[i][1]] == 1) && (career[log[i][0]] == 1 || career[log[i][1]] == 1)) {
                career[log[i][0]] = career[log[i][1]] = 1;
                flag = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (career[i] == 1) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
// int unique(int *a, int n){
//     while (*a != -1) {
//         if (*a == n) {
//             return 0;
//         }
//     }
//     return 1;
// }