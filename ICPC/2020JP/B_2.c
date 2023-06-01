//2022/07/01 19:51
//2022/07/01 20:26 AC.
#include <stdio.h>
int main(void){
    int m, n, p; //1<=m<=100, 0<=n<=1000, 1<=p<=m
    int career[100];
    while (1) {
        for (int i = 0; i < 100; i++) {
            career[i] = 0;
        }
        //入力
        scanf("%d %d %d", &m, &n, &p);
        if (m == 0 && n == 0 && p == 0) {
            break;
        }
        career[p - 1] = 1; //最初の感染者
        for (int t = 0; t < n; t++) {
            int tmp1, tmp2; //接触者2人それぞれのid
            scanf("%d %d", &tmp1, &tmp2);
            tmp1 = tmp1 - 1; //idと配列indexのズレを解消
            tmp2 = tmp2 - 1; //idと配列indexのズレを解消
            if ((career[tmp1] || career[tmp2])) { //どちらかが感染者なら感染
                career[tmp1] = career[tmp2] = 1;
            }
        }
        //感染者数を数え上げる
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (career[i] == 1) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}