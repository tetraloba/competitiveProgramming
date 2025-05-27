#include <stdio.h>
int Unique(int arr[], int, int);
int main(void){
    int N, W, A[301], unique[301] = {0}, unique_cnt = 0;
    scanf("%d %d", &N, &W);
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    /*for (int i = 0; i <= N; i++) { //debag
        printf("%d ", A[i]);
    }*/
    //putchar('\n'); //debag
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {
                if ((i != 0 && i == j) || (j != 0 && j == k) || (k != 0 && k == i) || A[i] + A[j] + A[k] > W) {
                    break;
                }
                if (Unique(unique, unique_cnt, A[i] + A[j] + A[k])) {
                    //putchar('\n'); //debag
                    unique[unique_cnt++] = A[i] + A[j] + A[k];
                }
            }
        }
    }
    /*for (int i = 0; i < unique_cnt; i++) { //debag
        printf("%d ", unique[i]);
    }
    putchar('\n'); //debag */
    printf("%d\n", unique_cnt);
    return 0;
}
int Unique(int arr[], int cnt, int num){
    for (int i = 0; i < cnt; i++) {
        if (arr[i] == num) {
            return 0;
        }
    }
    //printf("%d", num); //debag
    return 1;
}