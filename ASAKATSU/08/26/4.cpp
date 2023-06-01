//2022/08/26 07:56:35
//2022/08/26 08:09:31 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    int cnt[2] = {0};
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            cnt[0]++;
        } else if (cnt[0]) {
            cnt[0]--;
        } else {
            cnt[1]++;
        }
    }
    for (int i = 0; i < cnt[1]; i++) {
        cout << '(';
    }
    cout << S;
    for (int i = 0; i < cnt[0]; i++) {
        cout << ')';
    }
    cout << endl;
    return 0;
}
//僕これ知ってるよ！いもす法ってやつでしょう！やり方は知らないよ！！ 2022/08/26 07:57:17
//関係なくて草 2022/08/26 08:09:54