// 2023/11/04 21:05:56
// 2023/11/04 21:14:05 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int A[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        set<int> st;
        for (int j = 0; j < 9; j++) {
            st.insert(A[i][j]);
        }
        if (st.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int j = 0; j < 9; j++) {
        set<int> st;
        for (int i = 0; i < 9; i++) {
            st.insert(A[i][j]);
        }
        if (st.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }
    pair<int, int> lt[9] = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    for (auto [i, j] : lt) {
        set<int> st;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                st.insert(A[i + k][j + l]);
            }
        }
        if (st.size() != 9) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}