#include <stdio.h>
#include <math.h>
int main(void){
    int n, arr_score[1000], sum;
    double a2;
    while (scanf("%d", &n), n) {
        sum = a2 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr_score[i]);
            sum += arr_score[i];
        }
        for (int i = 0; i < n; i++) {
            a2 += pow(arr_score[i] - (double)sum / n, 2) / n;
        }
        printf("%f\n", sqrt(a2));

    }
    return 0;
}