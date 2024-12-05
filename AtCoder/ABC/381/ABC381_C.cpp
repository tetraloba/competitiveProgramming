// 2024/12/05 20:17:53
// 2024/12/05 20:26:50 WA
// 2024/12/05 20:31:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    int cnt1 = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            cnt1++;
            continue;
        }
        if (S[i] == '/') {
            i++;
            int ans_cnd = 0;
            while (i < N && S[i] == '2' && cnt1) {
                i++;
                cnt1--;
                ans_cnd++;
            }
            ans = max(ans, ans_cnd * 2 + 1);
            i--;
        }
        cnt1 = 0;
    }
    cout << ans << endl;
    return 0;
}
