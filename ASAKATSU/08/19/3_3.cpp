//2022/08/19 08:03:38
//2022/08/19 08:24:47 WA オーバーフロー
//2022/08/19 08:26:41 WA
//2022/08/19 08:59:19 AC.
//AGC040_A - ><
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    long long sum = 0;
    int cnt_past = 0;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        int cnt = 0;
        for (; i < S.size(); i++) {
            if (S[i] != c) {
                i--;
                break;
            }
            cnt++;
        }
        // cout << cnt << ' ' << (long long)cnt * (cnt + 1) / 2 << ' ' << min(cnt, cnt_past) << endl; //debug
        sum += (long long)cnt * (cnt + 1) / 2;
        if (c == '>') {
            sum -= min(cnt, cnt_past);
        }
        cnt_past = cnt;
    }
    cout << sum << endl;
    return 0;
}
// 500,000 * 500,000 / 2
// 250,000,000,000
// 125,000,000,000