// 2024/04/15 17:14:18
// 2024/04/15 18:08:57 無理
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    long long N;
    cin >> S >> N;
    vector<bool> N_bits;
    while (N) {
        N_bits.push_back(N % 2);
        N /= 2;
    }
    vector<bool> N_bin(N_bits.rbegin(), N_bits.rend());
    for (bool b : N_bin) {
        cout << (b ? '1' : '0');
    }
    cout << endl;
    long long ans = 0;
    if (S.size() < N_bin.size()) {
        for (char c : S) {
            ans *= 2;
            if (c != '0') {
                ans += 1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < S.size() - N_bin.size(); i++) {
        if (S[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        // S[i] = '0';
    }
    auto S_itr = S.rbegin();
    auto N_itr = N_bits.begin();
    int last_q = 0;
    for (; N_itr != N_bits.end(); N_itr++, S_itr++) {
        
    }
    bool flag = false; // 大小関係が確定した
    for (int i = S.size() - N_bin.size(); i < S.size(); i++) {
        ans *= 2;
        int N_i = i - (S.size() - N_bin.size());
        cout << S[i] << ',' << N_bin[N_i] << ' ';
        if (flag) {
            if (S[i] != '0') {
                ans += 1;
            }
        } else {
            if (S[i] != '1' && N_bin[N_i]) {
                flag = true;
            }
            if (S[i] == '1') {
                ans += 1;
                if (!N_bin[N_i]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
/*
?0110
  101
?01??
  100
?01??
  110
みたいなパターンがややこしいかな。

*/