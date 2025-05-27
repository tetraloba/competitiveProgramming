// 2024/05/14 11:43:25
// 2024/05/14 11:52:37 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    long long X;
    string S;
    cin >> N >> X >> S;
    stack<int> stk;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L' || S[i] == 'R') {
            stk.push(i);
        } else if (!stk.empty()) {
            S[stk.top()] = '-';
            S[i] = '-';
            stk.pop();
        }
    }
    // cout << S << endl; // debug
    long long cur = X;
    for (char c : S) {
        switch (c) {
            case 'U':
                cur = cur / 2;
                break;
            case 'L':
                cur = cur * 2;
                break;
            case 'R':
                cur = cur * 2 + 1;
                break;
        }
    }
    cout << cur << endl;
    return 0;
}
