// 2024/07/21 18:20:53
// 2024/07/21 19:05:40 AC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // vector<int> cnt_char(26);
    // for (char c : S) {
    //     cnt_char[c - 'a']++;
    // }

    sort(S.begin(), S.end());
    int all = 0, cnt = 0;
    do {
        all++;
        for (int i = 0; i <= N - K; i++) {
            bool flag = true;
            for (int l = i, r = i + K - 1; l <= r; l++, r--) {
                if (S[l] != S[r]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
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

K文字の回文の作り方
2: (2)
3: (3), (2,1)
4: (4), (2,2)x2
5: (5), (4,1), (3,2)x2, (2,2,1)x2
6: (6), (4,2)x3, (2,2,2)x6
abccba acbbca baccab bcaacb cabbac cbaabc
7: (7), (6,1), (4,3)x?, 
うーん・・・(2024/07/21 18:52:31)

K = 5
0 1 2 3 4
l = {0, 1, 2}
r = (K - 1) - l

K = 6
0 1 2 3 4 5
l = {0, 1, 2}
l = (K - 1) / 2までか。

*/
/*
next_permutation()使って順列さえ処理すれば、あとは愚直な実装で間に合うのね。
*/

