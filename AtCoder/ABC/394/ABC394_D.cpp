// 2025/02/25 14:14:26
// 2025/02/25 14:19:00 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool is_pair(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '<' && c2 == '>');
}
int main(){
    string S;
    cin >> S;
    stack<char> stk;
    for (char c : S) {
        if (stk.empty()) {
            stk.push(c);
            continue;
        }
        if (is_pair(stk.top(), c)) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    cout << (stk.empty() ? "Yes" : "No") << endl;
    return 0;
}
/*
括弧が対応しているかだね。スタックに詰めていけば良い。(2025/02/25 14:15:44)
*/
