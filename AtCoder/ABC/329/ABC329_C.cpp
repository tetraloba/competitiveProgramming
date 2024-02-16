// 2024/02/16 23:06:49
// 2024/02/16 23:18:26 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    S = S + 'A';
    int cnt[26] = {0};
    int tmp_cnt = 1;
    char tmp_char = S[0];
    for (int i = 1; i <= N; i++) {
        // cout << S[i] << ' ' << tmp_cnt << ' ' << tmp_char << endl;
        if (S[i] == tmp_char) {
            tmp_cnt++;
        } else {
            cnt[tmp_char - 'a'] = max(cnt[tmp_char - 'a'], tmp_cnt);
            tmp_cnt = 1;
            tmp_char = S[i];
        }
    }
    int ans = 0;
    for (int c : cnt) {
        ans += c;
    }
    cout << ans << endl;
    return 0;
}