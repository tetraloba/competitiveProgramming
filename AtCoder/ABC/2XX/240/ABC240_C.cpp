// 2024/02/25 14:12:42
// 2024/02/25 14:21:49 AC.
#include <iostream>
#include <set>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    set<int> st1;
    st1.insert(0);
    for (int i = 0; i < N; i++) {
        set<int> st2;
        int a, b;
        cin >> a >> b;
        for (int s : st1) {
            st2.insert(s + a);
            st2.insert(s + b);
        }
        st1 = st2;
    }
    cout << (st1.count(X) ? "Yes" : "No") << endl;
    return 0;
}
