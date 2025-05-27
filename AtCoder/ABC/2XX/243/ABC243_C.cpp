// 2024/02/25 14:29:49
// 2024/02/25 14:53:22 AC.
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    string S;
    cin >> S;

    map<int, map<int, char>> Ymp;
    for (int i = 0; i < N; i++) {
        Ymp[Y[i]][X[i]] = S[i]; // これってPythonだとできなかった気がするのよね。
    }
    for (const auto& [y, Xmp] : Ymp) {
        bool R = false;
        for (const auto& [x, s] : Xmp) {
            R |= s == 'R';
            if (R && s == 'L') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
// 解説読む限りこれでもまだ無駄があるのかな。
// https://atcoder.jp/contests/abc243/editorial/3542
