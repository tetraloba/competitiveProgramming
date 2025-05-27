// 2023/06/07 09:06:19
// 2023/06/07 09:26:09 WA. 負値のときmaxが0に。
// 2023/06/07 09:31:26 WA. いつものlli対応漏れかな。
// 2023/06/07 09:40:32 WA. lliキャスト漏れ
// 2023/06/07 09:52:12 AC.
#include <iostream>
#include <vector>
// #include <iomanip> // debug
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long int> AsumM(N, 0);
    for (int i = 0; i < M; i++) {
        AsumM[M - 1] += A[i];
    }
    for (int i = M; i < N; i++) {
        AsumM[i] = AsumM[i - 1] + A[i] - A[i - M];
    }

    // /* debug */
    // for (int i : A) {
    //     cout << setw(4) << i << ' ';
    // }
    // cout << endl;
    // for (int i : AsumM) {
    //     cout << setw(4) << i << ' ';
    // }
    // cout << endl;

    vector<long long int> anss(N, 0); // tmpでも対応化
    for (int i = 0; i < M; i++) {
        anss[M - 1] += (long long int)A[i] * (i + 1);
    }
    for (int i = M; i < N; i++) {
        anss[i] = anss[i - 1] - AsumM[i - 1] + (long long int)A[i] * M;
    }

    // /* debug */
    // for (int i : anss) {
    //     cout << setw(4) << i << ' ';
    // }
    // cout << endl;

    long long int max = anss[M - 1];
    for (int i = M; i < N; i++) {
        if (max < anss[i]) {
            max = anss[i];
        }
    }
    cout << max << endl;

    return 0;
}
// 5 4 -1 8
// 0 9 3 7
// 13 2 15
// 2 = 13 - 9 + -1 * M
// 15 = 2 - 3 + 8 * M