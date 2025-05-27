//2022/08/15 20:57:41
//2022/08/15 21:43:51 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    /* 宣言と入力 */
    int N, K;
    cin >> N >> K;
    vector<vector<int>> A;
    vector<int> T1(N);
    for (int i = 0; i < N; i++) {
        cin >> T1[i];
    }

    /* 配列を分割 */
    for (int i = 0; i < K; i++) {
        int L = N / K + (i < N % K ? 1 : 0);
        vector<int> T2(L);
        for (int j = 0; j < L; j++) {
            T2[j] = T1[i % K + K * j];
        }
        A.insert(A.end(), T2);
    }

    /* 各配列をソート */
    for (int i = 0; i < K; i++) {
        sort(A[i].begin(), A[i].end());
    }

    // /* debug用 配列書き出し */
    // for (int i = 0; i < K; i++) {
    //     int L = N / K + (i < N % K ? 1 : 0);
    //     for (int j = 0; j < L; j++) {
    //         cout << A[i][j] << (j != L - 1 ? ' ' : '\n');
    //     }
    // }

    /* 全体で昇順かどうか評価 */
    int tmp = A[0][0];
    int cnt = 0; //最終要素判定用
    for (int i = 0; cnt < N; i++) {
        for (int j = 0; j < K; j++) {
            // cout << tmp << ':' << A[j][i] << ' '; //debug用
            if (A[j][i] < tmp) {
                cout << "No" << endl;
                return 0;
            }
            tmp = A[j][i];
            if (++cnt == N) {
                break;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
// 1 2 3 4 5 6 7=> 2
// 1 3 5 7
// 2 4 6