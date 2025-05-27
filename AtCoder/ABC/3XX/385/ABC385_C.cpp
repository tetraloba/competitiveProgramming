// 2025/01/04 16:37:38
// 2025/01/04 18:12:26 3TLE
// 2025/01/04 18:52:24 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int tle(int N, vector<int> H){
    int H_MAX;
    for (int &h : H) {
        h--;
        H_MAX = max(H_MAX, h);
    }

    int ans = 1;
    vector<map<int, map<int, int>>> vmpmp(H_MAX + 1);
    for (int i = 0; i < N; i++) {
        auto& mpmp = vmpmp[H[i]];
        map<int, int> mp;
        mp[0] = 1;
        // cerr << mpmp.size() << endl; // debug
        for (auto [pre_i, pre_mp] : mpmp) {
            int tmp = pre_mp[i - pre_i];
            if (tmp == 0) {
                tmp = 1;
            }
            tmp++;
            mp[i - pre_i] = tmp;
            ans = max(ans, tmp);
        }
        mpmp[i] = mp;
    }

    // int ans = 0;
    // for (auto mpmp : vmpmp) {
    //     for (auto [index, mp] : mpmp) {
    //         // cerr << index << ":("; // debug
    //         for (auto [diff, num] : mp) {
    //             ans = max(ans, num);
    //             // cerr << diff << ':' << num << ", "; // debug
    //         }
    //         // cerr << ')' << endl; // debug
    //     }
    // }
    return ans;
}

int solve(int N, vector<int> H){
    for (int &h : H) {
        h--;
    }
    vector<vector<int>> vv(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        int step = i + 1;
        for (int j = 0; j < N; j++) {
            if (j < step) {
                vv[i][j] = 1;
                continue;
            }
            if (H[j] == H[j - step]) {
                vv[i][j] = vv[i][j - step] + 1;
            } else {
                vv[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // cerr << vv[i][j] << ' '; // debug
            ans = max(ans, vv[i][j]);
        }
        // cerr << endl; // debug
    }
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) {
        cin >> h;
    }
    int ans = solve(N, H);
    cout << ans << endl;
    return 0;
}
/*
選ぶ高さを全探索してO(HN)で間に合うんじゃないの。
H=3: 1,3,4,5
みたいな。
え、DPか？(2025/01/04 16:43:11)

8
5 7 5 7 7 5 7 7
   0  1  2  3  4  5  6  7
0
1
2
3
4  1  1  2  1  1  1  1  1
5
6     1     1   1    1   1
7

5: 0 2 5
7: 1 3 4 6 7
1(1,0), 3(2,2)(1,0), 4(2,3)()

   0  1  2  3  4  5  6  7
0  
1  1  
2     2
3  1  1  2
4  1  2     2
5     3  3     2
6  1  1  2  2     2
7  1  2     3  2     2

O(NHlogH)だとTLE…？(2025/01/04 18:23:08)
*/
/*
えー無理、普通に解けなかったんだが。(2025/01/04 18:52:38)
*/
