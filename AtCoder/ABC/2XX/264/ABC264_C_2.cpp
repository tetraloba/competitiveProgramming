// 2024/03/19 17:44:18
// 2024/03/19 18:12:41 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int H1, W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    for (auto &a : A) {
        for (int &i : a) {
            cin >> i;
        }
    }
    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    for (auto &b : B) {
        for (int &i : b) {
            cin >> i;
        }
    }
    int del_H_num = H1 - H2, del_W_num = W1 - W2;
    if (del_H_num < 0 || del_W_num < 0) {
        cout << "No" << endl;
        return 0;
    }
    vector<bool> del_H(H1 - del_H_num), del_W(W1 - del_W_num); // del_H[i]: i行目を削除するか
    for (int i = 0; i < del_H_num; i++) {
        del_H.push_back(true);
    }
    for (int i = 0; i < del_W_num; i++) {
        del_W.push_back(true);
    }
    bool ans = false;
    do {
        do {
            vector<int> idx_H, idx_W; // Aの、行列削除後のindexを取得するための配列
            for (int i = 0; i < H1; i++) {
                if (!del_H[i]) {
                    idx_H.push_back(i);
                }
            }
            for (int i = 0; i < W1; i++) {
                if (!del_W[i]) {
                    idx_W.push_back(i);
                }
            }
            bool flag = true;
            for (int i = 0; i < H2; i++) {
                for (int j = 0; j < W2; j++) {
                    if (A[idx_H[i]][idx_W[j]] != B[i][j]) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ans = true;
            }
        } while (next_permutation(del_W.begin(), del_W.end()));
    } while (next_permutation(del_H.begin(), del_H.end()));

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
/*
10C5 = 10 9 8 7 6 / 5 4 3 2 1 = 252
最大でもO(252 * 252 * 10 * 10)
*/
