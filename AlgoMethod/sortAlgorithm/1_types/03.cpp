//2022/08/18 22:25:13
//2022/08/18 22:29:27 AC.
#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<int>& A, int N){
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i != N - 1 ? ' ' : '\n');
    }
    return;
}
void insertionSort(vector<int>& A, int N){
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && A[j] < A[j - 1]; j--){
            swap(A[j], A[j - 1]);
        }
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
    insertionSort(A, N);
    return 0;
}