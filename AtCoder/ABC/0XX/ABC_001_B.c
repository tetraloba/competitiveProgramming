//2022/07/02 20:33
//2022/07/02 20:39 AC.
#include <stdio.h>
int main(void){
    int m, VV;
    scanf("%d", &m);
    if (m < 100) {
        VV = 00;
    } else if (m <= 5000) {
        VV = m * 10 / 1000;
    } else if (m <= 30000) {
        VV = m / 1000 + 50;
    } else if (m <= 70000) {
        VV = (m / 1000 - 30) / 5 + 80;
    } else {
        VV = 89;
    }
    printf("%02d\n", VV);
    return 0;
}