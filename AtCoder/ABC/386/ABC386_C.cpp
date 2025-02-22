// 2025/02/22 09:08:57
// 2025/02/22 09:22:50 6WA
// 2025/02/22 09:25:00 AC.
#include <iostream>
#include <vector>
using namespace std;
bool cmp(string S, string T) {
    if (T.size() < S.size()) {
        string tmp = T;
        T = S;
        S = tmp;
    }
    if (S.size() == T.size()) {
        int diff_cnt = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != T[i]) {
                diff_cnt++;
            }
        }
        return diff_cnt <= 1;
    }
    if (1 < T.size() - S.size()) {
        return false;
    }
    auto itr_t = T.begin();
    for (char s : S) {
        while (s != *itr_t) {
            if (itr_t == T.end()) {
                return false;
            }
            itr_t++;
        }
        if (itr_t == T.end()) {
            return false;
        }
        itr_t++;
    }
    return true;
}
int main(){
    int K;
    string S, T;
    cin >> K >> S >> T;
    cout << (cmp(S, T) ? "Yes" : "No") << endl;
    return 0;
}
/*
F問題は編集距離の問題か。まあCは文字数の変化から操作を特定すれば解ける。 (2025/02/22 09:11:04)
*/
