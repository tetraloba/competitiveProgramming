// 2025/12/12 21:45:30
// 2025/12/12 21:58:51 WA
// 2025/12/12 23:06:07 WA
// 2025/12/12 23:14:46 WA
// 2025/12/12 23:20:37 WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;

    vector<char> S;
    vector<char> stk;
    for (int q = 0; q < Q; q++) {
        for (char s : S) {
            cerr << s;
        }
        cerr << endl;
        int qn;
        char c;
        cin >> qn;
        switch (qn) {
            case 1:
                cin >> c;
                S.push_back(c);
                if (!stk.empty() && c == ')') {
                    if (stk.back() == '(') {
                        stk.pop_back();
                    } else {
                        stk.push_back(c);
                    }
                    cout << (stk.empty() ? "Yes" : "No") << endl;
                    break;
                }
                stk.push_back(c);
                cout << "No" << endl;
                break;
            case 2:
                if (stk.empty()) {
                    stk.push_back('(');
                } else {
                    if (S.back() == '(') {
                        stk.pop_back();
                    } else {
                        if (stk.back() == '(') {
                            stk.push_back('(');
                        } else {
                            stk.pop_back();
                        }
                    }
                }
                cout << (stk.empty() ? "Yes" : "No") << endl;
                S.pop_back();
                break;
        }
    }
    return 0;
}
/*
2025/12/12 21:46:44
まあ、右端しか操作しないなら消費していけば良いか。
2025/12/12 23:27:00
4
1 )
1 (
1 )
2
みたいなパターンで駄目なのは分かる。普通にカウント配列を作る方が良いのか。
*/

