//2022/08/19 09:42:29
//2022/08/19 09:58:26 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int diff(int a, int b){
    if (a < b) {
        return b - a;
    }
    return a - b;
}
double dis(int x1, int y1, int x2, int y2){
    return pow(diff(x1, x2) * diff(x1, x2) + diff(y1, y2) * diff(y1, y2), 0.5);
}
int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    double max = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double d = dis(x[i], y[i], x[j], y[j]);
            if (max < d) {
                max = d;
            }
        }
    }
    cout << fixed << max << endl;
    return 0;
}
// N = 100, N^2 = 10,000 組み合わせ全探索で行けるくね