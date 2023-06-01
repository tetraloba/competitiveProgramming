//2022/07/08  0:42
//
#include <stdio.h>
int main(void){
    int n, m; //n <= 50, m <= 10
    int arr[51][10][2];
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        int x0, y0, x1, y1;
        scanf("%d", &m);
        scanf("%d %d", &x0, &y0);
        arr[i][0][0] = 0;
        arr[i][0][1] = 0;
        scanf("%d %d", &x1, &y1);
        int shifter;
        if (x0 == x1) {
            if (0 < y1 - y0) {
                shifter = 0;
                arr[i][1][0] = y1 - y0; //+
                arr[i][1][1] = x0 - x1; //0
            } else {
                shifter = 1;
                arr[i][1][0] = y0 - y1; //+
                arr[i][1][1] = x1 - x0; //0
            }
        } else {
            if (0 < x1 - x0) {
                shifter = 2;
                arr[i][1][0] = x1 - x0; //+
                arr[i][1][1] = y1 - y0; //0
            } else {
                shifter = 3;
                arr[i][1][0] = x0 - x1; //+
                arr[i][1][1] = y0 - y1; //0
            }
        }
        for (int j = 2; j < m; j++) {
            x0 = x1;
            y0 = y1;
            scanf("%d %d", &x1, &y1);
            switch (shifter) {
              case 0:
                arr[i][j][0] = y1 - y0; //y
                arr[i][j][1] = x0 - x1; //-x
                break;
              case 1:
                arr[i][j][0] = y0 - y1; //-y
                arr[i][j][1] = x1 - x0; //x
                break;
              case 2:
                arr[i][j][0] = x1 - x0; //x
                arr[i][j][1] = y1 - y0; //y
                break;
              case 3:
                arr[i][j][0] = x0 - x1; //-x
                arr[i][j][0] = y0 - y1; //-y
                break;
            }
        }
    }
    puts("--ここから出力--");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d %d\n", arr[i][j][0], arr[i][j][1]);
        }
        puts("-----");
    }
    return 0;
}