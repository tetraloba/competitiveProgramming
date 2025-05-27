//2023/02/16 15:14:42
//2023/02/16 15:31:00 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    set<string> st;
    char set1[] = {'H' , 'D' , 'C' , 'S'};
    char set2[] = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        bool flag = false;
        for (char c1 : set1) {
            if (S[i][0] == c1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            for (char c2 : set2) {
                if (S[i][1] == c2) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            flag = false;
            if (st.find(S[i]) == st.end()) {
                flag = true;
                st.insert(S[i]);
            }
        }
        if (!flag) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}