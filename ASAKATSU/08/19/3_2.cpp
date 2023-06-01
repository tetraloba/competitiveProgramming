//2022/08/19 08:03:38
//2022/08/19 08:24:47 WA オーバーフロー
//2022/08/19 08:26:41 WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    long long sum = 0, crt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '<') {
            crt++;
            sum += crt;
        } else {
            int cnt = 0;
            for (; i < S.size(); i++) {
                if (S[i] != '>') {
                    i--;
                    break;
                }
                cnt++;
            }
            if (crt < cnt) {
                sum -= crt;
            } else {
                cnt--;
            }
            sum += cnt * (cnt + 1) / 2;
            crt = 0;
        }
    }
    cout << sum << endl;
    return 0;
}
// 500,000
// >>>>>>
// 500,000 * 500,000 / 2
// 250,000,000,000
// 125,000,000,000