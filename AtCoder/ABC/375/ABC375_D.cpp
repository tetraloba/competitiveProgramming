// 2024/12/01 11:39:01
// 2024/12/01 11:51:54 洗濯干しにより離脱
// 2024/12/01 12:11:05 再開
// 2024/12/01 12:22:36 AC.
#include <iostream>
#include <vector>
using namespace std;
long long combi_ctr(vector<int>& idxs){ // combination counter
    long long ans = 0;
    for (int i = 0; i < idxs.size(); i++) {
        ans += (long long)idxs[i] * i;
        ans -= (long long)idxs[i] * (idxs.size() - i - 1);
    }
    ans -= (long long)idxs.size() * (idxs.size() - 1) / 2;
    return ans;
}
int main(){
    string S;
    cin >> S;
    vector<vector<int>> idxss(26, vector<int>());
    for (int i = 0; i < S.size(); i++) {
        idxss[S[i] - 'A'].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        // cerr << i << ':' << combi_ctr(idxss[i]) << endl; // debug
        ans += combi_ctr(idxss[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
26(文字)×|S|は間に合うだろうし、各文字の数を数え上げたらうまい感じに計算できないか？(2024/12/01 11:40:50)
S[i]==S[k]の時間の文字数(k-i-1)を数えれば良い。(2024/12/01 11:41:54)
文字Aの場所が(1,4,6)の時、回文(AXA)は何通り？ → (4-1-1)+(6-4-1)+(6-1-1) 3C2通り有るのよね。組み合わせ…(2024/12/01 11:44:11)
これ高速化できるか。左の数字の個数回足して、右の数字の個数回引いて、文字数分引くのか。(2024/12/01 11:46:13)
→ combi_ctr()
*/
/*
解説はfor文1重か？うーん・・・
*/
