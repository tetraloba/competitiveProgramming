// 2023/11/04 17:10:16
// 2023/11/04 17:45:23 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
pair<int, int> arr[4] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}}; // 斜め方向処理用
/* C[i][j] が バツ印の中心ならtrue さもなくばfalse */
bool is_center(vector<vector<char>> C, int H, int W, int i, int j) {
    if (C[i][j] != '#') {
        return false;
    }
    for (auto [ai, aj] : arr) {
        if (i + ai < 0 || H <= i + ai || j + aj < 0 || W <= j + aj || C[i + ai][j + aj] != '#') {
            return false;
        }
    }
    return true;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> C[i][j];
        }
    }

    /* バツ印の中心座標を集合stに格納 */
    set<pair<int, int>> st;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (is_center(C, H, W, i, j)) {
                st.insert(make_pair(i, j));
            }
        }
    }

    /* debug stの中身の出力 */
    // for (auto [i, j] : st) {
    //     cout << '(' << i << ',' << j << ')' << ", ";
    // }
    // cout << endl;

    /* st内の各バツ印の大きさを求めてsizesに記録 */
    int N = min(H, W);
    vector<int> sizes(N);
    for (pair<int, int> c : st) {
        for (int size = 1; size <= N; size++) {
            bool end = false;
            for (auto [ai, aj] : arr) {
                if (c.first + ai * size < 0 || H <= c.first + ai * size || c.second + aj * size < 0 || W <= c.second + aj * size || C[c.first + ai * size][c.second + aj * size] != '#') {
                    sizes[size - 2]++;
                    end = true;
                    break;
                }
            }
            if (end) {
                break;
            }
        }
    }

    for (int size : sizes) {
        cout << size << ' ';
    }
    cout << endl;
    return 0;
}