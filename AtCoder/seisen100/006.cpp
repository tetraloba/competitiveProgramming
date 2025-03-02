// 2025/03/01 22:27:47
// 2025/03/01 22:49:27 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<bool> possible(1000);
    vector<bool> done1(10), done2(100);
    for (int i = 0; i < N; i++) {
        int n1 = S[i] - '0';
        if (done1[n1]) {
            continue;
        }
        done1[n1] = true;
        for (int j = i + 1; j < N; j++) {
            int n2 = S[j] - '0';
            if (done2[n1 * 10 + n2]) {
                continue;
            }
            done2[n1 * 10 + n2] = true;
            for (int k = j + 1; k < N; k++) {
                int n3 = S[k] - '0';
                possible[n1 * 100 + n2 * 10 + n3] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < possible.size(); i++) {
        ans += possible[i];
        // if (possible[i]) {
        //     cerr << i << ' '; // debug
        // }
    }
    cout << ans << endl;
    return 0;
}
