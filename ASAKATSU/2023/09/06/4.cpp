// 2023/09/06 07:59:43
// 2023/09/06 08:44:43 AC.
#include <iostream>
#include <vector>
#define NUM 1000000007
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<pair<long long int, long long int>> lesserNum(N, pair<long long int, long long int>(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (A[j] < A[i]) {
                lesserNum[i].first += i < j ? 1 : 0;
                lesserNum[i].second++;
            }
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << lesserNum[i].first << ',' << lesserNum[i].second << endl;
    // }
    long long int ans = 0;
    for (int i = 0; i < N; i++) {
        if (K % 2) {
            ans += (lesserNum[i].first + lesserNum[i].second * (K - 1) / 2 % NUM) % NUM * K % NUM;
        } else {
            ans += (lesserNum[i].first * 2 + lesserNum[i].second * (K - 1) % NUM) % NUM * (K / 2) % NUM;
        }
        ans %= NUM;
    }
    cout << ans << endl;
    return 0;
}
// 21 21 21
// 3
// 2
// 1
// 321 321 321
// 2 * K
// 132 132 132
// 3: 1,2
// 1 + (2 * (K - 1) + 1) * (K - 1) / 2
// 1 + 2 * (K - 1)
// 1 + 2 * (K - 2)
// 1 + 2 * (K - 3)
// (1 + 2 * (K - 1) + 1) * K / 2

// 2: 0,1
// 0 + 1 * (K - 1)