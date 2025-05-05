// 2025/05/05 21:54:04
// 2025/05/05 22:11:50 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N);
    for (int &t : T) {
        cin >> t;
    }
    sort(T.begin(), T.end());

    int ans = 0;
    int fp = 0; // 今いる中で最初に着いた人
    int lp; // 次のバスに乗れる最後の人
    while (lp < N) {
        int ft = T[fp]; // 今いる中で最初に着いた人の到着時刻
        lp = fp + 1;
        while (lp < N) {
            if (ft + K < T[lp] || C < lp - fp + 1) {
                lp--; // lpは乗れない
                break;
            }
            lp++;
        }
        // cerr << "DEBUG: bus " << fp << " to " << lp << endl;
        ans++;
        fp = lp + 1;
    }
    cout << ans << endl;
    return 0;
}
/*
貪欲かDPか。(2025/05/05 21:57:58)
バス停にいる中で一番早く到着したやつが怒り出すときに載せられるだけ載せて出発すればよいのよね。(2025/05/05 21:59:06)
*/
