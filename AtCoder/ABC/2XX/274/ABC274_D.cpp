// 2023/06/24 16:38:59
// 2023/06/24 17:21:44 AC
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    vector<int> A_x, A_y;
    for (int i = 2; i <= N; i++) {
        if (i % 2) {
            A_x.push_back(A[i]);
        } else {
            A_y.push_back(A[i]);
        }
    }
    set<int> st_x, st_y;
    st_x.insert(A[1] - x);
    st_y.insert(y);
    // for (int i : A_x) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : A_y) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    for (int i : A_x) {
        set<int> tmp;
        for (int j : st_x) {
            tmp.insert(j + i);
            tmp.insert(j - i);
        }
        st_x = tmp;
    }
    for (int i : A_y) {
        set<int> tmp;
        for (int j : st_y) {
            tmp.insert(j + i);
            tmp.insert(j - i);
        }
        st_y = tmp;
    }
    // for (int i : st_x) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (int i : st_y) {
    //     cout << i << ' ';
    // }
    // cout << endl;
    cout << (st_x.count(0) && st_y.count(0) ? "Yes" : "No") << endl;
    return 0;
}
// x軸組とy軸組に分けて、それぞれの総和が目的地との差分になれば良い。 2023/06/24 16:46:48
// (1000C0 + 1000C1 + 1000C2 + ... + 1000C500) * 2
// いや、+と-があるから総和じゃない。 2023/06/24 16:51:57
// 90度っていう縛りが有るから、xとyは交互。+-は各2通り。 2023/06/24 16:55:59

