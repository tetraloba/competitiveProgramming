//2022/08/09 08:14:04
//2022/08/09 08:27:03 AC.
#include <iostream>
using namespace std;
int main(){
    int N, M, x, y;
    bool red[100000] = {false};
    int num[100000];
    red[0] = true;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        num[i] = 1;
        // cout << i << ':' << num[i] << endl;
    }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        if (red[x - 1]) {
            red[y - 1] = true;
        }
        num[x - 1]--;
        num[y - 1]++;
        if (!num[x - 1]) {
            red[x - 1] = false;
        }
    }
    // cout << endl;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (red[i] && num[i]) {
            // cout << red[i] << ' ' << num[i] << endl;
            cnt++;
        }
    }
    // cout << endl;
    cout << cnt << '\n';
    return 0;
}