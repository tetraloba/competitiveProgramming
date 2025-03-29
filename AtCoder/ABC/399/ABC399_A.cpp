// 2025/03/29 21:00:09
// 2025/03/29 21:00:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
