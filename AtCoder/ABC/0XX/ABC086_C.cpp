// 2023/07/05 19:58:33
// 
#include <iostream>
#include <vector>
using namespace std;
int abs_dist(int a, int b){
    return a < b ? b - a : a - b;
}
int distance(int x1, int y1, int x2, int y2){
    return abs_dist(x1, x2) + abs_dist(y1, y2);
}
int main(){
    int N;
    cin >> N;
    vector<int> t(N + 1), x(N + 1), y(N + 1);
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i = 0; i < N; i++) {
        int d = distance(x[i], y[i], x[i + 1], y[i + 1]); // 地点間の距離
        int r = t[i + 1] - t[i]; // 歩ける距離
        if (r < d || (r - d) % 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}