//2022/08/13 12:25:03
//2022/08/13 12:33:15 AC.
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int>& A, int N){
    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i != N - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bool flag = true;
    while (1) {
        flag = false;
        for (int i = 0; i < N - 1; i++) {
            if (A[i + 1] < A[i]) {
                swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
        printVector(A, N);
    }
    return 0;
}