// 2023/11/14 21:15:58
// 2023/11/14 21:27:30 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    set<string> st;
    for (string s : S) {
        if (st.count(s)) {
            continue;
        } else {
            reverse(s.begin(), s.end());
            if (st.count(s)) {
                continue;
            }
            st.insert(s);
        }
    }    
    cout << st.size() << endl;
    return 0;
}