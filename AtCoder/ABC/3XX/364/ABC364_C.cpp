// 2024/08/06 20:49:42
// 2024/08/06 21:10:55 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N), B(N);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    long long sum_x = 0, sum_y = 0;
    int cnt_x = 0;
    for (int a : A) {
        sum_x += a;
        cnt_x++;
        if (X < sum_x) {
            break;
        }
    }
    int cnt_y = 0;
    for (int b : B) {
        sum_y += b;
        cnt_y++;
        if (Y < sum_y) {
            break;
        }
    }
    cout << min(cnt_x, cnt_y) << endl;
    return 0;
}
/*
DPで解けるよね？(2024/08/06 20:50:55)
なんだ、最小値か。
XとYそれぞれで降順ソートしたら良いだけね。(2024/08/06 21:06:39)
*/
