//2022/09/01 07:42:43
//2022/09/01 07:48:11 AC.
//ABC073_C - Write and Erase
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    set<int> st;
    for (int i = 0; i < N; i++) {
        auto itr = st.find(A[i]);
        if (itr == st.end()) {
            st.insert(A[i]);
        } else {
            st.erase(itr);
        }
    }
    cout << st.size() << endl;
    return 0;
}