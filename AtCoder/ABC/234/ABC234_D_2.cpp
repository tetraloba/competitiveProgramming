// 2024/04/09 11:11:52
// 2024/04/09 11:40:38 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int &p : P) {
        cin >> p;
        p--;
    }
    vector<int> index_of(N);
    for (int i = 0; i < N; i++) {
        index_of[P[i]] = i;
    }
    int ans = INT32_MAX;
    for (int i = 0; i < K; i++) {
        if (P[i] < ans) {
            ans = P[i];
        }
    }
    cout << ans + 1 << endl;
    for (int i = K; i < N; i++) {
        if (ans < P[i]) {
            for (int next_ans = ans + 1; next_ans < N; next_ans++) {
                if (index_of[next_ans] <= i) {
                    ans = next_ans;
                    break;
                }
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
/*
該当する値は常にN-K+1以下。
一度N-K+1になったらずっとN-K+1 (2024/04/09 11:27:36)
出力は広義単調増加
現在の値より小さいものが来たら変わらない、大きいものが来たら一つ大きいやつ。
*/
