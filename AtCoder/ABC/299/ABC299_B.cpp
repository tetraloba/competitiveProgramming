// 2023/11/03 12:05:03
// 2023/11/03 12:13:54 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    int same_max_i = -1, same_max = -1;
    int diff_max_i = 0;
    for (int i = 0; i < N; i++) {
        if (C[i] == T && same_max < R[i]) {
            same_max_i = i;
            same_max = R[i];
        }
        if (C[i] == C[0] && R[diff_max_i] < R[i]) {
            diff_max_i = i;
        }
    }

    cout << (same_max_i != -1 ? same_max_i + 1 : diff_max_i + 1) << endl;
    return 0;
}