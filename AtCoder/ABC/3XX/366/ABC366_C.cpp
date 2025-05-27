// 2024/11/30 11:51:39
// 2024/11/30 11:55:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;
    vector<int> cnt(1e6);
    int ans = 0;
    for (int q = 0; q < Q; q++) {
        int s, x;
        cin >> s;
        switch (s) {
            case 1:
                cin >> x;
                x--;
                cnt[x]++;
                if (cnt[x] == 1) {
                    ans++;
                }
                break;
            case 2:
                cin >> x;
                x--;
                cnt[x]--;
                if (cnt[x] == 0) {
                    ans--;
                }
                break;
            case 3:
                cout << ans << endl;
                break;
        }
    }
    return 0;
}
