// 2025/03/05 16:54:19
// 2025/03/05 18:00:00 中断
// 2025/03/05 20:48:41 再開
// 2025/03/05 21:03:25 15WA
// 2025/03/05 21:20:45 12WA
// 2025/03/05 21:26:07 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<string, string> byte_strings(string S, long long N){
    string ansN;
    while (N) {
        ansN.push_back(N % 2 + '0');
        N /= 2;
    }
    while (ansN.size() < S.size()) {
        ansN.push_back('0');
    }
    reverse(ansN.begin(), ansN.end());
    if (ansN.size() == S.size()) {
        return {S, ansN};
    }

    string ansS = S;
    reverse(ansS.begin(), ansS.end());
    while (ansS.size() < ansN.size()) {
        ansS.push_back('0');
    }
    reverse(ansS.begin(), ansS.end());
    return {ansS, ansN};
}
long long str2ll(string s) {
    long long res = 0;
    for (char c : s) {
        res *= 2;
        res += (c - '0');
    }
    return res;
}
long long solve(string S0, long long N){
    auto [S, T] = byte_strings(S0, N);
    bool all1 = false;
    vector<int> idxq0s, idxq1s;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == T[i]) {
            continue;
        }
        if (all1) {
            if (S[i] == '?') {
                S[i] = '1';
            }
            continue;
        }
        if (S[i] == '0' && T[i] == '1') {
            all1 = true;
            for (int idx : idxq1s) {
                S[idx] = '1';
            }
            for (int idx : idxq0s) {
                S[idx] = '0';
            }
        }
        if (S[i] == '1' && T[i] == '0') {
            if (idxq1s.size() == 0) {
                return -1;
            }
            for (int idx : idxq1s) {
                S[idx] = '1';
            }
            S[idxq1s.back()] = '0';
            for (int idx : idxq0s) {
                if (idx < idxq1s.back()) {
                    S[idx] = '0';
                } else {
                    S[idx] = '1';
                }
            }
            all1 = true;
        }
        if (S[i] == '?') {
            if (T[i] == '1') {
                idxq1s.push_back(i);
            } else {
                if (idxq1s.size() == 0) {
                    S[i] = '0';
                } else {
                    idxq0s.push_back(i);                    
                }
            }
        }
    }
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            S[i] = T[i];
        }
    }
    // cerr << S << '\n' << T << endl; // debug
    return str2ll(S);
}
int main(){
    string S;
    long long N;
    cin >> S >> N;
    cout << solve(S, N) << endl;
}
/*
SとNを比較した時，同じ桁は無視
上位の位から見たときに01が出た時点で以降の?は1で良い。
その前に10が出たら不可能。
?0なら?は0
?1が問題か。
?1はキープしておいて，以降10が出たら最初のやつが0，以降の?は1？
    01が出たら?は1か。
*/
