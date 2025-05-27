// 2024/05/05 12:21:58
// 2024/05/05 12:51:28 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    map<string, string> mp;
    for (int i = 0; i < N; i++) {
        string S, T;
        cin >> S >> T;
        mp[S] = T;
    }
    for (auto& [s, t] : mp) {
        if (t == "" ) {
            continue;
        }
        if (mp.count(t) == 0) {
            t = "";
            continue;
        }
        set<string> st;
        st.insert(s);
        string tgt = s, next;
        while (true) {
            next = mp[tgt];
            if (next == "") {
                break;
            }
            mp[tgt] = "";
            if (st.count(next)) {
                cout << "No" << endl;
                return 0;
            }
            st.insert(next);
            tgt = next;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
