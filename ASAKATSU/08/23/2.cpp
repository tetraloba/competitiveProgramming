//2022/08/23 07:30:45
//2022/08/23 07:39:36 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    int crtt = 0, crtx = 0, crty = 0;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        int dist = max(crtx - x, x - crtx) + max(crty - y, y - crty);
        int time = t - crtt;
        if (time < dist || (time - dist) % 2) { //奇数だと戻ってこれない
            flag = false;
            break;
        }
        crtt = t;
        crtx = x;
        crty = y;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}