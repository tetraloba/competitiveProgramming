// 2024/02/24 19:48:45
// 2024/02/24 19:56:15 AC.
#include <iostream>
#include <set>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    set<int> st;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    int ans;
    for (ans = 0; ans < K; ans++) {
        if (st.find(ans) == st.end()) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}