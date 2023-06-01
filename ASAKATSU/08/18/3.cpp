//2022/08/18 07:34:45
//2022/08/18 07:38:15 WA
//2022/08/18 08:03:08 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    string s;
    int k;
    cin >> s >> k;
    set<string> st;
    int N = s.size();
    for (int i = 0; i <= N - k; i++) {
        string tmp;
        for (int j = 0; j < k; j++) {
            tmp += s[i + j];
        }
        st.insert(tmp);
    }
    // for (auto i : st) {
    //     cout << i << endl;
    // }
    cout << st.size() << endl;
    return 0;
}