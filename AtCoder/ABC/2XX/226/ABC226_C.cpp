//2022/08/15 18:53:05
//2022/08/15 19:19:11 WA.
//2022/08/15 19:36:45 AC. あー難しい。
#include <iostream>
#include <vector>
using namespace std;
void acquire(int i, vector<vector<int>>& A, vector<int>& K, vector<int>& T, long long& time, bool* flag){
    // cout << i << K[i] << endl;
    for (int j = 0; j < K[i]; j++) {
        if (!flag[A[i][j] - 1]) {
            acquire(A[i][j] - 1, A, K, T, time, flag);
        }
    }
    flag[i] = true;
    time += T[i];
    return;
}
int main(){
    long long ans = 0; //time
    int N;
    cin >> N;
    vector<int> T(N), K(N);
    vector<vector<int>> A; //空のvector
    bool flag[200000] = {false}; //falseで初期化?
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> K[i];
        vector<int> tmp(K[i]);
        for (int j = 0; j < K[i]; j++) {
            cin >> tmp[j];
        }
        A.insert(A.end(), tmp);
    }
    acquire(N - 1, A, K, T, ans, flag);
    cout << ans << endl;
    return 0;
}