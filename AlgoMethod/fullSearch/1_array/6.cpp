//2022/08/13 16:54:07
//2022/08/13 16:55:35 AC.
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
    int max = -101;
    for (int i = 0; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    cout << max << endl;
    return 0;
}