#include <stdio.h>
#include <math.h>
int main(void){
    int n, arr_x[1000], arr_y[1000], arr_dif[1000];
    double D1 = 0, D2pow2 = 0, D2, D3pow3 = 0, D3, Dinf = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_y[i]);
        arr_dif[i] = arr_x[i] - arr_y[i];
        if (arr_dif[i] < 0) {
            arr_dif[i] = -arr_dif[i];
        }
        D1 += (double)arr_dif[i];
        if (Dinf < arr_dif[i]) {
            Dinf = arr_dif[i];
        }
    }
    for (int i = 0; i < n; i++) {
        D2pow2 += pow(arr_dif[i], 2);
        D3pow3 += pow(arr_dif[i], 3);
    }
    printf("%f\n%f\n%f\n%f\n", D1, sqrt(D2pow2), pow(D3pow3, 1.0 / 3), Dinf);

    return 0;
}