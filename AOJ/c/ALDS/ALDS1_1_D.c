#include <stdio.h>
int main(void){
    int n, arr[200000], min, max = 1, max_profit = -1000000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            min = arr[i];
        }
    }
    for (int i = 1; i < n; i++) {
        if (max_profit < arr[i] - min) {
            max_profit = arr[i] - min;
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("%d\n", max_profit);
    return 0;
}