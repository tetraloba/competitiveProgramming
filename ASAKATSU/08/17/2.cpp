//2022/08/17 07:47:22
//2022/08/17 07:54:36 AC.
//ABC021_B - 嘘つきの高橋くん
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, a, b, K, P[100];
    set<int> st;
    cin >> N >> a >> b >> K;
    bool flag = true;
    for (int i = 0; i < K; i++) {
        cin >> P[i];
        if (P[i] == a || P[i] == b) {
            flag = false;
        }
        st.insert(P[i]);
    }
    if (st.size() != K) {
        flag = false;
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}