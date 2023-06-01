//2022/08/28 07:31:49
//2022/08/28 08:17:27 AC.
//ABC181_C - Collinearity
#include <iostream>
#include <vector>
using namespace std;
struct Pos{
    int x;
    int y;
};
int main(){
    int N;
    cin >> N;
    vector<Pos> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) {
                    continue;
                }
                if (a[i].x == a[j].x) {
                    if (a[k].x == a[i].x) {
                        // cout << '#' << i << ' ' << j << ' ' << k << endl;
                        cout << "Yes" << endl;
                        return 0;
                    } else {
                        continue;
                    }
                }
                if (a[i].y == a[j].y) {
                    if (a[k].y == a[i].y) {
                        // cout << '$' << i << ' ' << j << ' ' << k << endl;
                        cout << "Yes" << endl;
                        return 0;
                    } else {
                        continue;
                    }
                }
                if ((double)(a[k].x - a[i].x) / (a[j].x - a[i].x) == (double)(a[k].y - a[i].y) / (a[j].y - a[i].y)) {
                    // cout << a[i].x << ' ' << a[j].x << ' ' << a[k].x << ' ' << a[i].y << ' ' << a[j].y << ' ' << a[k].y << endl;
                    // cout << (a[k].x - a[i].x) / (a[j].x - a[i].x) << "==" << (a[k].y - a[i].y) / (a[j].y - a[i].y) << endl;
                    // cout << '%' << i << ' ' << j << ' ' << k << endl;
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
//x軸またはy軸に平行はすぐに分かるが、斜めは…？
//10^2 C 2 * 10^2 まあ、全探索でも間に合うか…