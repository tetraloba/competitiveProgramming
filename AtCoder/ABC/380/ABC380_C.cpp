// 2024/12/04 21:52:45
// 2024/12/04 22:13:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int K0, ctx;
    if (S[0] == '0') {
        K0 = K;
        ctx = 0;
    } else {
        K0 = K - 1;
        ctx = 1;
    }
    int phase[2] = {0};
    phase[ctx]++;
    int cntK0 = 0;
    cout << S[0];
    for (int i = 1; i < S.size(); i++) {
        if (S[i] != S[i - 1]) {
            ctx = !ctx;
            phase[ctx]++;
        }
        if (ctx == 0 && phase[ctx] == K0) {
            cntK0++;
            continue;
        }
        if (ctx == 0 && phase[ctx] == K0 + 1) {
            while (cntK0) {
                cout << 0;
                cntK0--;
            }
        }
        cout << S[i];
    }
    while (cntK0) {
        cout << 0;
        cntK0--;
    }
    cout << endl;
    return 0;
}
/*
えどういうこと？
K-1またはK番目の0の塊の出力を一旦スキップすれば良いんでなくて…？
何が難しいの…？(2024/12/04 21:55:11)
*/
