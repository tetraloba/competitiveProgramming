// 2023/11/04 20:34:26
// 2023/11/04 20:55:47 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    string Td;
    cin >> Td;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    set<int> st;
    for (int i = 0; i < N; i++) {
        if (S[i].length() == Td.length()) {
            // if (S[i] == Td) {
            //     st.insert(i + 1);
            // } else {
                
            // }
            int cnt = 0;
            for (int j = 0; j < S[i].length(); j++) {
                if (S[i][j] != Td[j]) {
                    cnt++;
                }
            }
            if (cnt < 2) {
                st.insert(i + 1);
            }
        } else if (S[i].length() == Td.length() - 1) {
            int j, k;
            for (j = 0, k = 0; j < S[i].length() && k < Td.length(); j++, k++) {
                if (S[i][j] != Td[k]) {
                    j--;
                }
            }
            if (k - j < 2) {
                st.insert(i + 1);
            }
        } else if (S[i].length() - 1 == Td.length()) {
            int j, k;
            for (j = 0, k = 0; j < S[i].length() && k < Td.length(); j++, k++) {
                if (S[i][j] != Td[k]) {
                    k--;
                }
            }
            if (j - k < 2) {
                st.insert(i + 1);
            }
        }
    }

    cout << st.size() << endl;
    for (int s : st) {
        cout << s << ' ';
    }
    cout << endl;
    return 0;
}