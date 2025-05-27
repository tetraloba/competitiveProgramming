// 2024/02/28 18:02:41
// 2024/02/28 18:43:35 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (vector<int> &v : A) {
        for (int &a : v) {
            cin >> a;
        }
    }
    vector<bool> mrs; // move_rights
    for (int i = 0; i < H - 1; i++) {
        mrs.push_back(false);
    }
    for (int i = 0; i < W - 1; i++) {
        mrs.push_back(true);
    }
    int ans = 0;
    do {
        bool flag = true;
        int h = 0, w = 0;
        set<int> st;
        st.insert(A[h][w]);
        for (bool right : mrs) {
            if (right) {
                w++;
            } else {
                h++;
            }
            if (st.count(A[h][w])) {
                flag = false;
                break;
            }
            st.insert(A[h][w]);
        }
        ans += flag;
    } while (next_permutation(mrs.begin(), mrs.end()));
    cout << ans << endl;
    return 0;
}
// 2^18 通り
// 2分木の深さ優先探索と言ったところかな？スタックにメモしておけば良さそう。
// bit全探索で良いのか。 (2024/02/28 18:08)
// bit全探索って深さ優先よな…？
// 大嘘。行き先が決まっているので並べ替え問題ですね。((H - 1) + (W - 1)) C (H - 1) (2024/02/28 18:20)
// ↑が最大で18C9 = 48,620なので、48620 * 18 の全探索で良いのでは() (2024/02/28 18:23)
