// 2024/04/12 13:03:06
// 2024/04/12 13:07:46 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> D(M);
    for (int &d : D) {
        cin >> d;
    }
    sort(D.begin(), D.end());
    vector<bool> dp(N + 1);
    dp[0] = true;
    for (int i = 0; i < N; i++) {
        if (!dp[i]) {
            continue;
        }
        for (int d : D) {
            if (N < i + d) {
                continue;
            }
            dp[i + d] = true;
        }
    }
    cout << (dp[N] ? "Yes" : "No") << endl;
    return 0;
}
