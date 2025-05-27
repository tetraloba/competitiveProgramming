// 2024/05/28 14:43:52
// 2024/05/28 14:52:08 AC.
#include <iostream>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    stack<int> stk;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        while (!stk.empty()) {
            if (stk.top() != a) {
                break;
            }
            stk.pop();
            a++;
        }
        stk.push(a);
    }
    // while (!stk.empty()) {
    //     cout << stk.top() << ' ';
    //     stk.pop();
    // }
    // cout << endl;
    cout << stk.size() << endl;
    return 0;
}
