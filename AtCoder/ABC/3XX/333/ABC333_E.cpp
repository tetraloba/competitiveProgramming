// 2024/03/28 15:12:39
// 2024/03/28 15:30:05 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> t(N), x(N);
    for (int i = 0; i < N; i++) {
        int tmp_t, tmp_x;
        cin >> tmp_t >> tmp_x;
        t[i] = --tmp_t; x[i] = --tmp_x;
    }

    /* 拾うべきポーションを求める */
    vector<stack<int>> vs(N); // 各ポーションの場所
    vector<bool> get(N); // ポーションを拾うかどうか
    for (int i = 0; i < N; i++) {
        if (t[i]) { // モンスター
            if (vs[x[i]].empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                get[vs[x[i]].top()] = true;
                vs[x[i]].pop();
            }
        } else { // ポーション
            vs[x[i]].push(i);
        }
    }

    /* Kを求める */
    int num = 0; // ポーションの所持数
    int K = 0; // ポーションの所持数の最大値
    for (int i = 0; i < N; i++) {
        if (t[i]) {
            num--;
        } else if (get[i]) {
            num++;
            if (K < num) {
                K = num;
            }
        }
    }

    /* 答えを出力する */
    cout << K << endl;
    for (int i = 0; i < N; i++) {
        if (!t[i]) { // ポーション
            cout << (get[i] ? 1 : 0) << ' ';
        }
    }
    cout << endl;
    return 0;
}
/*
モンスターから一番近いポーションだけ拾っていけば良い。
が、連続で複数出る場合が厄介か。
普通に各ポーションの場所のリスト用意してしまえば良さそう？
*/
