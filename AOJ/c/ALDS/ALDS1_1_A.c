#include <stdio.h>
int insertionSort(int A[], int N){
    int tmp, j;
    for (int i = 1; i < N; i++) {
        tmp = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j+1] = tmp;
        for (int k = 0; k < N; k++) {
            printf("%d", A[k]);
            if (k != N - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
int main(void){
    int N, A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            putchar(' ');
        }
    }
    putchar('\n');
    insertionSort(A, N);
    return 0;
}