// 2024/03/30 21:01:07
// 2024/03/30 21:09:06 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    string S;
    cin >> S;
    set<string> st;
    for (int i = 0; i < S.size(); i++) {
        for (int j = i; j < S.size(); j++) {
            string S_part(S.begin() + i, S.begin() + j + 1);
            st.insert(S_part);
        }
    }
    // for (string s : st) {
    //     cout << s << ' ';
    // }
    // cout << endl;
    cout << st.size() << endl;
    return 0;
}
/*
はじめと終わり100通りずつくらい
*/