//2022/08/15 17:54:06
//2022/08/15 18:00:48 TLEじゃね？わからん。
//2022/08/15 18:28:17 TLE 知ってた。結局setに甘えるしか無いんかねえ…
//2022/08/15 18:50:59 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    set<vector<int>> st;
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<int> A(L);
        for (int j = 0; j < L; j++) {
            cin >> A[j];
        }
        st.insert(A);
    }
    cout << st.size() << endl;
    return 0;
}