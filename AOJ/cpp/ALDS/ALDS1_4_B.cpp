//2022/08/21 16:18:04
//2022/08/21 16:50:50 TLE
//2022/08/21 17:04:48 AC.
#include <iostream>
#include <vector>
using namespace std;
int binarySearch(int T, vector<int>& S, int n){
    // S.push_back(T);
    int f = 0;
    while (n != 0) {
        if (T < S[f + n / 2]) {
            n = n / 2;
        } else if (S[f + n / 2] < T) {
            f = f + n / 2 + 1;
            n -= n / 2 + 1;
        } else {
            return f + n / 2;
        }
    }
    return -1;
}
// 4 5 : 4
// 1 2 3 4 5 : 4
// 0 1 2 3 4 5
int main(){
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        if(binarySearch(T[i], S, n) != -1) {
            cnt++;
            // cout << "i:" << i << " func:" << binarySearch(T[i], S, n) << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}