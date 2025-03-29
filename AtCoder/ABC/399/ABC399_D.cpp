// 2025/03/29 21:18:21
// 2025/03/29 21:50:35 8WA
// 2025/03/29 22:05:23 7WA
// 2025/03/29 22:22:38 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector<int> anss;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> A(2 * N);
        for (int &a : A) {
            cin >> a;
            a--;
        }

        /* debug */
        // cerr << endl;
        // for (int a : A) {
        //     cerr << a << ' ';
        // }
        // cerr << endl;

        vector<vector<map<int, int>>> neighbors(N);
        for (int i = 0; i < 2 * N; i++) {
            map<int, int> mp;
            if (0 < i) {
                mp[A[i - 1]]++;
            }
            if (i < 2 * N - 1) {
                mp[A[i + 1]]++;
            }
            neighbors[A[i]].push_back(mp);
        }

        /* debug */
        // for (int i = 0; i < N; i++) {
        //     cerr << i << ": ";
        //     for (auto [k, v] : neighbors[i][0]) {
        //         cerr << k << ' ';
        //     }
        //     cerr << "| ";
        //     for (auto [k, v] : neighbors[i][1]) {
        //         cerr << k << ' ';
        //     }
        //     cerr << endl;
        // }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (neighbors[i][0][i]) {
                continue; // i同士が既に隣接
            }
            for (auto [k, v] : neighbors[i][0]) {
                if (neighbors[k][0][k]) {
                    continue; // k同士が既に隣接
                }
                if (neighbors[i][0][k] && neighbors[i][1][k] && neighbors[k][0][i] && neighbors[k][1][i]) {
                    ans++;                    
                }
            }
        }
        anss.push_back(ans / 2); // i=aとi=bでダブルカウントされるため/2する
    }
    for (int ans : anss) {
        cout << ans << endl;
    }
    return 0;
}
/*
bとして考えられるのはaの隣りにある高々4通りのみか。(2025/03/29 21:21:47)
各値について隣接する数のリストを持てば良い？(2025/03/29 21:22:17)

abab (1,2),(2,1) O
abaXb (1,1),(2,0) X
abXab (1,1),(1,1) O
abXaXb (1,0),(1,0) X
aXbXaXb (0,0),(0,0) X
aabb (0,1),(1,0) X
abba (1,1),(1,1) O いやこれだめなのか。bが既に隣接しているから条件を満たさない。(2025/03/29 22:03:32)
aaXbb (0,0),(0,0) X
*/
