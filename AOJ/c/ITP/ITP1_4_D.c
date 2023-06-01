#include <stdio.h>
int main(void){
    int n, a, min, max;
    long long sum;
    scanf("%d", &n);
    scanf("%d", &a);
    min = a; max = a; sum = a;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        sum += a;
        if (min > a) {
            min = a;
        } else if (max < a) {
            max = a;
        }
    }
    printf("%d %d %lld\n", min, max, sum);

    return 0;
}