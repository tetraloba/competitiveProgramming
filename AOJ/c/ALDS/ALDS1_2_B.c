//2022/06/27  0:49
#include <stdio.h>
int *minPtr(int*, int);
int selectionSort(int*, int);
int main(void){
    int N, A[100];
    //Input
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    //Sort Count
    int count = selectionSort(A, N);
    //Output
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
    printf("%d\n", count);
    return 0;
}
int selectionSort(int *A, int N){
    int count = 0;
    for (int i = 0; i < N; i++) {
        int *min = minPtr(A, N - i);
        if (*A != *min) {
            int tmp = *A;
            *A = *min;
            *min = tmp;
            count++;
        }
        A++;
    }
    return count;
}
int *minPtr(int *A, int N){
    int *min = A;
    for (int i = 0; i < N; i++) {
        if (*A < *min) {
            min = A;
        }
        A++;
    }
    return min;
}