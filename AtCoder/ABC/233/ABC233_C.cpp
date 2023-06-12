// 2023/06/12 22:20:46
// 2023/06/12 23:30:23 WA.
// 2023/06/12 23:32:29 WA.
// 2023/06/12 23:33:38 WA.
// 2023/06/12 23:54:48 RE.
// 2023/06/13 00:21:54 AC.
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
int main(){
    int N;
    long long X; // <= 10^18
    // long long mult[100000];
    cin >> N >> X;
    vector<vector<int>> a(N); // <= 10^9
    // vector<vector<int>> a;
    int mult_num = 1; // 個数の総積 <= 10^5
    for (int i = 0; i < N; i++) {
        int tmp_L; // 袋iのボールの個数 <= 10^5
        cin >> tmp_L;
        mult_num *= tmp_L;
        a[i] = vector<int>(tmp_L);
        // a.push_back(vector<int>(tmp_L));
        for (int j = 0; j < tmp_L; j++) {
            cin >> a[i][j];
        }
    }
    // cout << mult_num << endl; // debug
    vector<long long> mult(mult_num, 1); // ボールの値の積 <= 10^18?
    int rep = mult_num;
    for (int i = 0; i < N; i++) {
        rep /= a[i].size();
        for (int j = 0; j < mult_num; j++) {
            // cout << "mult[" << j << "] *= " << a[i][j / rep % a[i].size()] << endl; // debug
            if (mult[j] && numeric_limits<long long>::max() / mult[j] < a[i][j / rep % a[i].size()]) { // オーバーフロー
                mult[j] = 0;
            } 
            mult[j] *= a[i][j / rep % a[i].size()];
        }
    }
    int cnt = 0;
    for (int i = 0; i < mult_num; i++) {
        // cout << mult[i] << ' '; // debug
        if (mult[i] == X) {
            cnt++;
        }
    }
    // cout << endl; // debug
    cout << cnt << endl;
    return 0;
}

// 6 (ab, ABC)
//     aaabbb 2:3
//     ABCABC 2:1

// 24 (ab, ABC, 1234)
//     aaaaaaaaaaaabbbbbbbbbbbb 2:12
//         i / 12 % 2
//     AAAABBBBCCCCAAAABBBBCCCC 2:3:4
//         i / 4 % 3
//     123412341234123412341234 2:3:4:1
//         i / 1 % 4

// L_i >= 2 かつ L_i (1 <= i <= N) の総積は10^5を超えない。
// 2^17 = 131072 > 10^5 であるから N < 17