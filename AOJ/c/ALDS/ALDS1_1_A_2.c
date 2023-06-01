//2022/07/06 18:49
#include <stdio.h>
void InsertionSort(int *arr, int N){
    for (int i = 1; i < N; i++) {
        int tmp = arr[i];
        int j = i - 1;
        while (0 <= j && tmp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}
int main(void){
    int N, arr[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    InsertionSort(arr, N);
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i != N - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}