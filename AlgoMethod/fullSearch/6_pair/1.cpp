//2022/08/15 13:47:56
//2022/08/15 13:50:08 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] + A[j] <= K) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}