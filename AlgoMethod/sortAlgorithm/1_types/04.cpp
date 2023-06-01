//2022/08/18 22:34:08
//2022/08/18 23:31:15 AC.
#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>& A, int N){
    if (!N) {
        return;
    }
    vector<int> L, R;
    int X = N / 2;
    for (int i = 0; i < N; i++) {
        if (i != X) {
            if (A[i] < A[X]) {
                L.push_back(A[i]);
            } else {
                R.push_back(A[i]);
            }
        }
    }
    quickSort(L, L.size());
    quickSort(R, R.size());
    L.push_back(A[X]);
    A.clear();
    A.insert(A.end(), L.begin(), L.end());
    A.insert(A.end(), R.begin(), R.end());
    return;
}
void printArray(vector<int>& A, int N){
    for (int i = 0; i < N; i++) {
        cout << A[i] << (i != N - 1 ? ' ' : '\n');
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
    quickSort(A, N);
    printArray(A, N);
    return 0;
}