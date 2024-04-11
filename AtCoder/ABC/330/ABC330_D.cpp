// 2024/04/11 21:05:31
// 2024/04/11 21:21:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
    }
    vector<int> cnt_ro(N), cnt_co(N); // 各行、各列のoの数
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                cnt_ro[i]++;
                cnt_co[j]++;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                ans += (cnt_ro[i] - 1) * (cnt_co[j] - 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
