// 2023/11/04 14:56:03
// 2023/11/04 15:16:07 WA ans Overflowするな…
// 2023/11/04 15:18:05 WA borderが…

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    int i = 0;
    int cl = 0; // CapsLock 0:false 1:true 2:any
    unsigned long long int ans = 0;
    while (i < S.length()) {
        unsigned int cnt = 0;
        char fc = S[i];
        while (S[i] == fc) {
            i++;
            cnt++;
        }
        if (cl == 2) {
            int min = X * cnt;
            int shift = 0; // shiftを使ったかどうか。 X(未使用) なら 0, Y(使用) なら 1, 両方あり得るなら 2
            if (Z + Y * cnt < min) {
                min = Z + Y * cnt;
                shift = 1;
            } else if (Z + Y * cnt == min) {
                shift = 2;
            }
            if (Y * cnt < min) {
                min = Z + Y * cnt;
                shift = 1;
            } else if (Y * cnt == min) {
                shift = shift == 2 || shift == 0 ? 2 : 1;
            }
            if (Z + X * cnt < min) {
                min = Z + X * cnt;
                shift = 0;
            } else if (Z + X * cnt == min) {
                shift = shift == 2 || shift == 1 ? 2 : 0;
            }
            ans += min;
            cl = shift ? ((fc == 'A') ? 0 : 1) : ((fc == 'A') ? 1: 0);
        } else if (cl == (fc == 'A')) { // CapsLockの状態と一致
            if (X * cnt < Z + Y * cnt) {
                ans += X * cnt;
            } else if (X * cnt == Z + Y * cnt) {
                ans += X * cnt;
                cl = 2;
            } else {
                ans += Z + Y * cnt;
                cl = !cl;
            }
        } else {
            if (Y * cnt < Z + X * cnt) {
                ans += Y * cnt;
            } else if (Y * cnt == Z + X * cnt) {
                ans += Y * cnt;
                cl = 2;
            } else {
                ans += Z + X * cnt;
                cl = !cl;
            }
        }
        cout << i << ':' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
// 連続するそれぞれの組(aa..., AA...)についてCapsLock使うのとどっちが早いかを貪欲法的に選んでいけば良い？
// 同値だった場合にどちらにすれば良いか分からんのよなあ… CapsLockをどちらと解釈しても良い状態にすればよいのか・・・
// aaAaAaaAAAAaAaaAaAAaaaAAAAA
// 2: 1*2
// 2: 2*1
// 1
// 2
// 2
// 8: 2*4, 4 + 1*4
// 1
// 2
// 2: 1*2
// いやこれ前から考えていくのでは無理か。前で損な選択でもCapsLockの状態によっては後ろでめっちゃ得する可能性あるもんな…
