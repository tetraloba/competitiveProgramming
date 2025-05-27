// 2024/02/24 18:09:29
// 2024/02/24 18:25:44 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    vector<char> stk(S.size());
    int stk_size = 0;
    for (char s : S) {
        stk[stk_size] = s;
        stk_size++;
        while (3 <= stk_size && stk[stk_size - 3] == 'A' && stk[stk_size - 2] == 'B' && stk[stk_size - 1] == 'C') {
            stk_size -= 3;
        }
    }
    for (int i = 0; i < stk_size; i++) {
        cout << stk[i];
    }
    cout << endl;
    return 0;
}
// AABCBC
// ABABCC
