// 2024/07/11 13:07:01
// 2024/07/11 13:32:27 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int &p : P) {
        cin >> p;
        p--;
    }

    vector<int> Pi(N);
    for (int i = 0; i < N; i++) {
        Pi[P[i]] = i;
    }

    set<int> st;
    for (int i = 0; i < K; i++) {
        st.insert(Pi[i]);
    }
    int ans = *st.rbegin() - *st.begin();
    for (int i = K; i < N; i++) {
        st.insert(Pi[i]);
        st.erase(Pi[i - K]);
        int cnd = *st.rbegin() - *st.begin();
        ans = cnd < ans ? cnd : ans;
    }

    cout << ans << endl;
    return 0;
}
/*
1~Nまでの各数字について、数列の何番目に有るか(添字)を管理する配列を作って、
N-M+1通りについて添字の最大値と最小値の差を求めれば良い。(2024/07/11 13:23:40)
set使えばヌルゲーか。(2024/07/11 13:28:28)
*/
