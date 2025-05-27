// 2024/11/30 11:56:22
// 2024/11/30 12:18:05 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) {
        cin >> h;
    }
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // cerr << i << ' ' << T << endl; // debug
        if (T % 3 == 1) {
            T++;
            H[i]--;
            if (H[i] <= 0) {
                continue;
            }
        }
        if (T % 3 == 2) {
            T++;
            H[i] -= 3;
            if (H[i] <= 0) {
                continue;
            }
        }
        /* この時点で T % 3 == 0 */
        // if (H[i] <= 0) {
        //     continue;
        // }
        T += H[i] / 5 * 3;
        H[i] %= 5;
        if (H[i] <= 0) {
            continue;
        }
        T++;
        H[i]--;
        if (H[i] <= 0) {
            continue;
        }
        T++;
        H[i]--;
        if (H[i] <= 0) {
            continue;
        }
        T++;
        H[i] -= 3;
        if (H[i] <= 0) {
            continue;
        }
    }
    cout << T << endl;
    return 0;
}
/*
Tは攻撃回数
3回攻撃で5ダメージを1セットにする (2024/11/30 11:59:08)

3
1 12 123

1
11 8 7 6 3 2 1 -2
122 121 118

*/
