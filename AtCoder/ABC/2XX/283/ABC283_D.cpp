// 2024/04/25 19:08:53
// 2024/04/25 19:19:39 AC.
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
int main(){
    string S;
    cin >> S;
    set<char> st;
    stack<set<char>> stk;
    stk.push(set<char>());
    for (char s : S) {
        if (s == '(') {
            stk.push(set<char>());
        } else if (s == ')') {
            for (char c : stk.top()) {
                st.erase(c);
            }
            stk.pop();
        } else {
            if (st.count(s)) {
                cout << "No" << endl;
                return 0;
            }
            stk.top().insert(s);
            st.insert(s);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
