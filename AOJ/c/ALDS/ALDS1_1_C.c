#include <stdio.h>
#include <math.h>
int judge(int a){
    for (int i = 2; i <= sqrt((double)a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main(void){
    int n, tmp, j = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (judge(tmp)) {
            j++;
        }
    }
    printf("%d\n", j);
    return 0;
}