//2022-07-23 20:32:05
//2022-07-23 20:39:23 AC.
#include <stdio.h>
int unique(int, int*, int);
int main(void){
    int N, tmp, set[1000] = {0};
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if (unique(tmp, set, cnt)) {
            set[cnt++] = tmp;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
int unique(int a, int *arr, int n){
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            return 0;
        }
    }
    return 1;
}