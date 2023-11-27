// 2023/11/17 22:16:27
// 2023/11/17 22:31:03 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    set<int> st;
    int tgt = 1;
    int init;
    st.insert(1);
    while (true) {
        tgt = A[tgt];
        if (st.count(tgt)) {
            init = tgt;
            break;
        }
        st.insert(tgt);
    }

    int cnt = 0;
    tgt = init;
    while (true) {
        cnt++;
        tgt = A[tgt];
        if (tgt == init) {
            break;
        }
    }
    cout << cnt << endl;

    tgt = init;
    while (true) {
        cout << tgt << ' ';
        tgt = A[tgt];
        if (tgt == init) {
            break;
        }
    }
    cout << endl;
    return 0;
}