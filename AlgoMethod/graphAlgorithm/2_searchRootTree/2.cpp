// 2023/06/07 10:51:58
// 2023/06/07 11:20:47 AC.
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 1; i < N; i++) {
        cin >> A[i];
    }
    vector<set<int>> vs(N);
    for (int i = 1; i < N; i++) {
        vs[A[i]].insert(i);
    }

    // /* debug */
    // for (int i = 0; i < N - 1; i++) {
    //     cout << i << ':';
    //     for (int j : vs[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    stack<int> stk;
    stk.push(0);
    while (stk.size()) {
        cout << stk.top() << ' ';
        set<int> st = vs[stk.top()];
        stk.pop();
        for (auto itr = st.rbegin(); itr != st.rend(); itr++) {
            stk.push(*itr);
        }
    }
    cout << endl;
    return 0;
}
// stackでsetから逆順に取り出すと行きがけ順
// queueだと幅優先探索かな。