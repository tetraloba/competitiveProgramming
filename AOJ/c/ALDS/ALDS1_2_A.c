#include <stdio.h>
int bubbleSort(int A[], int N){
    int flag = 1, count = 0;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}
int main(void){
    int N, arr[100], count;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    count = bubbleSort(arr, N);
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i != N - 1) {
            putchar(' ');
        }
    }
    printf("\n%d\n", count);
    return 0;
}