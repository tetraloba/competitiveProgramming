// 2023/11/04 20:25:12
// 
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    string Td;
    cin >> N >> Td;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    set<int> st;
    for (int k = 0; k < N; k++) {
        int i = 0, j = N - 1;
        while (i < N && S[k][i] == Td[i]) {
            i++;
        }
        while (i < j && S[k][j] == Td[j]) {
            j--;
        }
        if (i == j) {
            st.insert(k + 1);
        }
    }
    cout << st.size() << endl;
    for (int s : st) {
        cout << s << ' ';
    }
    cout << endl;
    return 0;
}

