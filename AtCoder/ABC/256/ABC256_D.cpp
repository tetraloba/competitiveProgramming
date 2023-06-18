// 2023/06/18 20:40:51
// 2023/06/18 20:50:07 WA
// 2023/06/18 20:59:02 WA
// 2023/06/18 21:05:54 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> LR(N);
    for (int i = 0; i < N; i++) {
        cin >> LR[i].first >> LR[i].second;
    }
    sort(LR.begin(), LR.end());
    int left = LR[0].first, right = LR[0].second;
    for (int i = 0; i < N - 1; i++) {
        if (right < LR[i + 1].first) {
            cout << left << ' ' << right << endl;
            left = LR[i + 1].first;
            right = LR[i + 1].second;
        } else if (right < LR[i + 1].second) {
            right = LR[i + 1].second;
        }
    }
    cout << left << ' ' << right << endl;
    return 0;
}