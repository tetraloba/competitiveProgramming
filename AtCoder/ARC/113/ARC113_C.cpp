// 2025/05/03 16:48:08
// 2025/05/03 17:01:19 12WA
// 2025/05/03 17:15:59 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    string S;
    cin >> S;
    const int N = S.size();
    map<char, int> cnt_char;
    long long ans = 0;
    for (int i = N - 1 - 2; 0 <= i; i--) {
        cnt_char[S[i + 2]]++;
        if (S[i] == S[i + 1] && S[i] != S[i + 2]) {
            ans += N - (i + 2) - cnt_char[S[i]];
            cnt_char.clear();
            cnt_char[S[i]] = N - (i + 2);
        }
        // cerr << ans << '(' << S[i] << ':' << cnt_char[S[i]] << ',' << S[i + 1] << ':' << cnt_char[S[i + 1]] << ',' << S[i + 2] << ':' << cnt_char[S[i + 2]] << ')' << endl;
    }
    cout << ans << endl;
    return 0;
}
/*
右からやっていくのが正解か？(2025/05/03 16:49:05)
aabbcccdeef
aabbabccadaabbc
aabaの場合は1回しかできないのか(2025/05/03 16:52:20)
敢えて変えないことで得することってあるのか？(2025/05/03 16:53:00)
sample弱そうだなあ…(2025/05/03 17:01:08)
*/
/*
分からないので解説を読んだ。(2025/05/03 17:10:09)
abbbcbbccca
1(c:2,c:2,a:0)
1(c:3,c:3,c:3)
1(b:0,c:4,c:4)
5(b:5,b:5,c:0)
5(c:0,b:6,b:6)
5(b:7,c:0,b:7)
5(b:8,b:8,c:0) <- ??
5(b:9,b:9,b:9)
5(a:0,b:10,b:10)
5
N=11

i=2のときが問題。
置き換えた時の足す数を間違えていたな。
*/
