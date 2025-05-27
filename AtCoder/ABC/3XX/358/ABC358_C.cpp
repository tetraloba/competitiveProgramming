// 2024/06/23 21:17:30
// 2024/06/23 21:45:31 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
    }

    int ans = M;
    int seq_max = 1;
    for (int i = 0; i < N; i++) {
        seq_max *= 2;
    }
    for (int seq = 0; seq < seq_max; seq++) {
        vector<bool> done(M);
        int se = seq;
        int cnt_visit = 0;
        for (int i = 0; i < N; i++) {
            if (se % 2) {
                for (int j = 0; j < M; j++) {
                    done[j] = done[j] | S[i][j] == 'o';
                }
                cnt_visit++;
            //     cout << '1'; // debug
            // } else {
            //     cout << '0'; // debug
            }
            se /= 2;
        }
        // cout << ' '; // debug
        bool all_done = true;
        for (bool b : done) {
            if (!b) {
                all_done = false;
            }
        }
        // cout << cnt_visit << (all_done ? 'O' : 'X') << endl; // debug
        if (all_done && cnt_visit < ans) {
            ans = cnt_visit;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
動的計画法っぽい？思い出さないとなあ(2024/06/23 21:19)
制約小さいのかあ！(2024/06/23 21:22)
行く行かないの2^10 * ?
bit全探索か。
*/

/*
時刻が9時間遅い。Ubuntuの影響か・・・
12 -> 21 手動修正
*/
