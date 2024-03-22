// 2024/03/22 14:47:48
// 2024/03/22 15:22:08 WA
// 2024/03/22 16:23:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int cnt[26] = {0};
    for (int i = 0; i < S.size(); i++) {
        cnt[S[i] - 'a']++;
    }
    int cnt_sums[26] = {0};
    for (int i = 0; i < 26 - 1; i++) {
        cnt_sums[i + 1] = cnt_sums[i] + cnt[i];
    }
    // for (int i = 0; i < 26; i++) {
    //     cout << cnt_sums[i] << ' ';
    // }
    // cout << endl;
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += (long long)cnt[i] * (cnt_sums[i]);
    }
    for (int i = 0; i < 26; i++) {
        if (2 <= cnt[i]) {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
abcbeb

bacbeb
cbabeb
bbcaeb
ebcbab
bbcbea

acbbeb
abcbeb
aecbbb
abcbeb // 重複

abbceb
abebcb
abbbec

abcebb
abcbeb // 重複

abcbbe

aa 1 - 0
aaa 3 - 2
aaaa 6 - 5
aaaaa 10 - 9

aab 3 - 0
aaab 6 - 2
aaaab 10 - 5

aaabc 10 - 2
aaabcd 15 - 2

aaabbc 15 - 3
aaabbb 15 - 2 - 2 - 1

aaabbbccc 36 - 2 - 2 - 2 - 2

aaaabbb 21 - 5 - 2 - 1

aaaabbbb

1 + 各数字について「数*(自分以外の数)」かな。

*/
