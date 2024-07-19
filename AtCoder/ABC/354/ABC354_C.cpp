// 2024/07/19 22:19:48
// 2024/07/19 22:36:36 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> C(N);
    for (auto &c : C) {
        cin >> c.first >> c.second;
    }

    vector<pair<int, int>> S(C);
    sort(S.rbegin(), S.rend());

    set<pair<int, int>> st;
    int min_cost = INT32_MAX;
    for (auto s : S) {
        if (s.second < min_cost) {
            min_cost = s.second;
            st.insert(s);
        }
    }

    cout << st.size() << endl;
    for (int i = 0; i < N; i++) {
        if (st.count(C[i])) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}
