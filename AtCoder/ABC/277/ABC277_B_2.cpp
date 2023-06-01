//2023/02/16 15:14:42
//2023/02/16 15:31:00 AC.
//2023/02/16 15:42:56 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    char st1[] = {'H', 'D', 'C', 'S'};
    char st2[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    set<char> cs[2];
    for (char c : st1) cs[0].insert(c);
    for (char c : st2) cs[1].insert(c);

    int N; cin >> N;
    set<string> st;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        if (cs[0].find(S[0]) == cs[0].end() || cs[1].find(S[1]) == cs[1].end() || st.find(S) != st.end()) {
            cout << "No" << endl;
            return 0;
        }
        st.insert(S);
    }
    cout << "Yes" << endl;
    return 0;
}