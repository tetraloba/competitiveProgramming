//2022/08/21 21:14:38
//2022/08/21 21:32:36 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    char G[H + 1][W + 1];
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> G[i][j];
        }
    }
    int i = 1, j = 1;
    set<pair<int, int>> st;
    st.insert(make_pair(i, j));
    bool flag = false;
    while (1) {
        // cout << i << ' ' << j << ' ' << G[i][j] << endl;
        if (G[i][j] == 'U') {
            if (i != 1) {
                i--;
                if (st.find(make_pair(i, j)) == st.end()) {
                    st.insert(make_pair(i, j));
                } else {
                    flag = true;
                    break;
                }
                continue;
            }
            break;
        }
        if (G[i][j] == 'D') {
            if (i != H) {
                i++;
                if (st.find(make_pair(i, j)) == st.end()) {
                    st.insert(make_pair(i, j));
                } else {
                    flag = true;
                    break;
                }
                continue;
            }
            break;
        }
        if (G[i][j] == 'L') {
            if (j != 1) {
                j--;
                if (st.find(make_pair(i, j)) == st.end()) {
                    st.insert(make_pair(i, j));
                } else {
                    flag = true;
                    break;
                }
                continue;
            }
            break;
        }
        if (G[i][j] == 'R') {
            if (j != W) {
                j++;
                if (st.find(make_pair(i, j)) == st.end()) {
                    st.insert(make_pair(i, j));
                } else {
                    flag = true;
                    break;
                }
                continue;
            }
            break;
        }
    }
    if (flag) {
        cout << -1 << endl;
        return 0;
    }
    cout << i << ' ' << j << endl;
    return 0;
}