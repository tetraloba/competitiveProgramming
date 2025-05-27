// 2023/05/26 23:31:47
// 
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    set<string> st{"and", "not", "that", "the", "you"};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (st.find(str) != st.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}