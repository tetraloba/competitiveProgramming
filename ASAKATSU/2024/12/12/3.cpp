// 2024/12/12 07:30:18
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    for (int &f : F) {
        cin >> f;
    }

    sort(F.rbegin(), F.rend()); // 運賃が高い順に巡る

    vector<long long> sumD(N); // i日目からD日間の運賃合計
    for (int i = 0; i < N && i < D; i++) {
        sumD[0] += F[i];
    }
    for (int i = 1; i < N; i++) {
        sumD[i] = sumD[i - 1] - F[i - 1] + (i + D - 1 < N ? F[i + D - 1] : 0);
    }

    /* debug */
    // for (int i = 0; i < N; i++) {
    //     cerr << sumD[i] << ' ';
    // }
    // cerr << endl;

    long long ans = 0;
    int i = 0;
    while (i < N) {
        if (sumD[i] < P) {
            break;
        }
        ans += P;
        i += D;
    }
    while (i < N) { // 残りは通常運賃で巡る
        ans += F[i];
        i++;
    }
    cout << ans << endl;
    return 0;
}
/*
貪欲で良し(2024/12/12 07:31:50)
*/
