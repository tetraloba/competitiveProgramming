// 2023/06/24 16:38:59
// 2023/06/24 17:21:44 AC
// 2023/06/24 17:46:21 AC.
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
    set<int> st_x{A[1]}, st_y{0}; // 存在し得る座標
    for (int i = 2; i <= N; i++) {
        if (i % 2) { // X軸方向の移動
            set<int> tmp;
            for (int j : st_x) {
                tmp.insert(j + A[i]);
                tmp.insert(j - A[i]);
            }
            st_x = tmp;
        } else { // y軸方向の移動
            set<int> tmp;
            for (int j : st_y) {
                tmp.insert(j + A[i]);
                tmp.insert(j - A[i]);
            }
            st_y = tmp;
        }
    }
    cout << (st_x.count(x) && st_y.count(y) ? "Yes" : "No") << endl; // 最終的に座標(x,y)に居れる可能性があればYes
    return 0;
}
// x軸組とy軸組に分けて、それぞれの総和が目的地との差分になれば良い。 2023/06/24 16:46:48
// (1000C0 + 1000C1 + 1000C2 + ... + 1000C500) * 2
// いや、+と-があるから総和じゃない。 2023/06/24 16:51:57
// 90度っていう縛りが有るから、xとyは交互。+-は各2通り。 2023/06/24 16:55:59

