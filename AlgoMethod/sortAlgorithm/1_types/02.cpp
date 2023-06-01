//2022/08/18 22:01:03
//2022/08/18 22:15:46 AC.
#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<int>& A, int N){
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i != N - 1 ? ' ' : '\n');
    }
    return;
}
void selectionSort(vector<int>& A, int N){
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        swap(A[i], A[minIndex]);
        printArray(A, N);
    }
    return;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    selectionSort(A, N);
    return 0;
}