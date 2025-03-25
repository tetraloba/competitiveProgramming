// 2025/03/25 11:22:26
// 2025/03/25 12:53:10 6TLE 16WA
// 2025/03/25 12:57:49 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX_LENGTH 16
using namespace std;
string solve(int N, int M, vector<string> S, vector<string> T) {
    if (N == 1 && S[0].size() <= 2) {
        return "-1";
    }
    set<string> stT(T.begin(), T.end()), stS; // stS: Sから生成可能な文字列の集合
    
    /* debug */
    // cerr << "stT: ";
    // for (string s : stT) {
    //     cerr << s << ' ';
    // }
    // cerr << endl;

    sort(S.begin(), S.end()); // for next_permutation()
    int sum_S_size = 0; // アンダースコアを除く文字数
    for (string s : S) {
        sum_S_size += s.size();
    }
    vector<int> us_str; // i番目の塊が 0:アンダースコア 1:文字列
    for (int i = 0; i < MAX_LENGTH - sum_S_size - (S.size() - 1); i++) { // アンダースコアの数
        us_str.push_back(0);
    }
    for (int i = 0; i < S.size(); i++) { // 文字列部分の数
        us_str.push_back(1);
    }

    /* debug */
    // cerr << "us_str: ";
    // for (int i : us_str) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    do {
        do {
            vector<int> uss; // (i,i+1)番目間のアンダースコアの数
            int us_num = 1;
            for (int i = 0; i < us_str.size(); i++) {
                if (us_str[i] == 0) {
                    us_num++;
                } else {
                    uss.push_back(us_num);
                    us_num = 1;
                }
            }
            uss.push_back(us_num);

            /* debug */
            // cerr << "uss: ";
            // for (int i : uss) {
            //     cerr << i << ' ';
            // }
            // cerr << endl;

            string s;
            for (int i = 0; i < S.size(); i++) {
                s += S[i];
                if (i == S.size() - 1) {
                    continue;
                }
                for (int j = 0; j < uss[i]; j++) {
                    s.push_back('_');
                }
            }
            stS.insert(s);
        } while (next_permutation(us_str.begin(), us_str.end()));
    } while (next_permutation(S.begin(), S.end()));
    
    /* debug */
    // cerr << "stS: ";
    // for (string s : stS) {
    //     cerr << s << ' ';
    // }
    // cerr << endl;

    set<string> res;
    set_difference(stS.begin(), stS.end(), stT.begin(), stT.end(), inserter(res, res.end()));

    /* debug */
    // cerr << "res: ";
    // for (string s : res) {
    //     cerr << s << ' ';
    // }
    // cerr << endl;

    return res.size() ? *res.begin() : "-1";
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for (string &s : S) {
        cin >> s;
    }
    for (string &t : T) {
        cin >> t;
    }

    cout << solve(N, M, S, T) << endl;
    return 0;
}
/*
まずTを解析するか？必要ないかもしれないが…(2025/03/25 11:27:23)
Siは1文字以上で
1_2_3_4_5_6_7_8 だと15文字なのよね。
|S|=1 で |S0|<=2 の場合だけ字数不足で -1
sigma(|Si|) + (N - 1)は固定なので，16までの残りをアンダースコアの配置替えできる。(2025/03/25 11:34:33)
- 8! = 40320
- 7箇所へのアンダースコア1つの分配 ~ 2箇所へのアンダースコア11個の分配 13C2 = 78
- 10^5からの検索
計算量見積もりが難しいなあ。(2025/03/25 11:38:21)
可能な文字列の集合を作ってしまって集合Tを減算するので良いのでは・・・(2025/03/25 11:50:02)
アンダースコア入れない(sigma(|Si|) < 16)パターンも有るから13C3 = 286かしら・・・
*/
