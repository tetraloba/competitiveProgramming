#include <iostream>
#include <vector>
using namespace std;
int main(){
    while (true) {
        int n, m, p, q;
        cin >> n >> m >> p >> q;

        if (n == 0 && m == 0 && p == 0 && q == 0) {
            break;
        }

        vector<vector<int>> vv(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            vv[0][i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            int j = 1;
            while (j < x) {
                vv[i][j] = vv[i - 1][j];
                j++;
            }
            vv[i][x] = vv[i - 1][x + 1];
            vv[i][x + 1] = vv[i - 1][x];
            j = x + 2;
            while (j <= n) {
                vv[i][j] = vv[i - 1][j];
                j++;
            }
        }
        
        q = vv[m][q];
        int ans = 0, ans_y = 0;

        // OK check
        if (p == q) { // p == vv[0][p]
            cout << "OK" << endl;
            // return 0; // whileのときはcontinue;
            continue;
        }

        for (int i = 0; i <= m; i++) { // 最初の並びを除く => 大嘘。除かない。
            for (int j = 1; j < n; j++) {
                if (vv[i][j] == p && vv[i][j + 1] == q) {
                    ans = j;
                    ans_y = i;
                    break;
                } else if (vv[i][j] == q && vv[i][j + 1] == p) {
                    ans = j;
                    ans_y = i;
                    break;
                }
            }
            if (ans) {
                break;
            }
        }

        // debug
        // for (int i = 0; i <= m; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << vv[i][j] << ' '; 
        //     }
        //     cout << endl;
        // }

        if (ans) {
            cout << ans << ' ' << ans_y << endl;
        } else {
            cout << "NG" << endl;
        }
    }

}