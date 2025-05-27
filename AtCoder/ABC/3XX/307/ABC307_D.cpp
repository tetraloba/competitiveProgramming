// 2024/05/07 15:38:18
// 2024/05/07 16:02:01 18WA
// 2024/05/07 16:17:17 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<char> ans(N);
    int cur = 0; // cursor
    stack<int> stk;
    for (char s : S) {
        ans[cur] = s;
        if (s == '(') {
            stk.push(cur);
        }
        cur++;
        if (s == ')' && !stk.empty()) {
            cur = stk.top(); stk.pop();
        }
        // /* debug */
        // for (int c = 0; c < cur; c++) {
        //     cout << ans[c];            
        // }
        // cout << endl;
    }
    for (int c = 0; c < cur; c++) {
        cout << ans[c];            
    }
    cout << endl;
    return 0;
}
/*
a(b(d))c
a(b(d 1,3
a(b)

*/
