// 2023/11/04 22:15:11
// 2023/11/04 22:26:42 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<pair<int, int>> win_cnt(N);
    for (int i = 0; i < N; i++) {
        win_cnt[i].second = N - 1 - i;
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                win_cnt[i].first++;
            }
        }
    }

    sort(win_cnt.rbegin(), win_cnt.rend());

    for (pair<int, int> wc : win_cnt) {
        cout << N - wc.second << ' ';
    }
    cout << endl;
    return 0;
}
// 勝ち数は降順で番号は昇順か。
// 負け数とかにした方がやりやすいか？
