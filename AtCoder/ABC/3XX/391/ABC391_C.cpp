// 2025/02/24 10:04:43
// 2025/02/24 10:12:55 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> num(N, 1), pos(N); // 巣iの鳩の数，鳩iの居る巣
    for (int i = 0; i < N; i++) {
        pos[i] = i;
    }

    int ans = 0;
    for (int q = 0; q < Q; q++) {
        int query;
        cin >> query;
        switch (query) {
            case 1:
                int P, H;
                cin >> P >> H;
                P--; H--;
                num[pos[P]]--;
                if (num[pos[P]] == 1) {
                    ans--;
                }
                pos[P] = H;
                num[H]++;
                if (num[H] == 2) {
                    ans++;
                }
                break;
            case 2:
                cout << ans << endl;
                break;
        }
        // for (int i = 0; i < N; i++) {
        //     cerr << num[i] << ' ';
        // }
        // cerr << endl;
        // for (int i = 0; i < N; i++) {
        //     cerr << pos[i] << ' ';
        // }
        // cerr << endl;
    }
    return 0;
}
