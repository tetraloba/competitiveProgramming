//2022/08/14 11:09:02
//2022/08/14 11:11:21 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int min = 1000000001, max = 0;
    for (int i = 0; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
        }
        if (A[i] < min) {
            min = A[i];
        }
    }
    cout << max - min << endl;
    return 0;
}