//2022/08/15 13:53:12
//2022/08/15 13:55:02 AC.
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
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i] <= A[j] && A[k] <= A[j]) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}