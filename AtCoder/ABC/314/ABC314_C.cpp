// 2024/02/20 20:22:49
// 2024/02/20 20:40:30 AC.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> C(N);
    vector<vector<char>> vv(M, vector<char>()); // 色毎の文字配列
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
        vv[C[i]].push_back(S[i]);
    }

    vector<int> cnt(M);
    for (int i = 0; i < M; i++) {
        cnt[i] = vv[i].size() - 1; // 各文字配列の一番後ろで初期化
    }

    for (int i = 0; i < N; i++) {
        cout << vv[C[i]][cnt[C[i]]];
        cnt[C[i]] = cnt[C[i]] == vv[C[i]].size() - 1 ? 0 : cnt[C[i]] + 1; // cnt[C[i]]++ のループver.
    }
    cout << endl;
    return 0;
}