// 2024/07/21 18:20:53
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    sort(S.begin(), S.end());
    int all = 0, cnt = 0;
    do {
        all++;
        for (int i = 1; i < N - 1; i++) {
            if (S[i] == S[i - 1] || S[i] == S[i + 1] || S[i - 1] == S[i + 1]) {
                cnt++;
                break;
            }
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << all - cnt << endl;
    return 0;
}
/*
うーん、全体から回文を含むものを引くのが良いのかな？
1文字は回文ではないのね？
aa
aba
abba <- aa に含まれるか
abcba
abccba <- aa に含まれる

aa以外は奇数だけやっていけばよいか。
abacaba は abaに含まれるから
abcdcba だけ見れば良いね。(2024/07/21 18:24:56)

並べ替え(順列)は10! = 10 9 8 7 6 5 4 3 2 1 = 720 * 720 * 7 = 3,628,800
あー 10! * 10^2 だと間に合わないか。
10! * 10 は間に合う？(2024/07/21 18:27:42)
あーabcbaはabaに含まれるのか。
じゃあaaとabaだけ見れば良い。
各文字について両隣を見て、両隣が同じか一方が自身と同じなら良いわけだよね。(2024/07/21 18:29:13)
回文の長さ指定(K)有るのか。忘れてた。(2024/07/21 18:36:00)
じゃあ長さKの回分の作り方と、その時の他の文字の並べ方を計算したほうが良いのかな。(2024/07/21 18:37:38)
*/
