// 2024/12/10 08:00:07
// 2024/12/10 08:06:53 AC.
// ABC381_C - 11/22 Substring
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            cnt++;
            continue;
        }
        if (S[i] == '/') {
            int ans_cond = 0;
            i++;
            while (cnt && i < N && S[i] == '2') {
                cnt--;
                ans_cond++;
                i++;
            }
            ans = max(ans, ans_cond * 2 + 1);
            i--;
        }
        cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
