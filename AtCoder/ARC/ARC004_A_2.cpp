//2022/08/19 09:42:29
//2022/08/19 09:58:26 AC.
//2022/08/19 10:18:05 AC. 構造体を用いて見通しを改善するなど。pairだとfirst,secondで分かりにくいのよねえ…
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Pos{
    int x;
    int y;
};
double dis(Pos pos1, Pos pos2){
    return pow((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y), 0.5);
}
int main(){
    int N;
    cin >> N;
    vector<Pos> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i].x >> pos[i].y;
    }
    double max = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            double d = dis(pos[i], pos[j]);
            if (max < d) {
                max = d;
            }
        }
    }
    cout << fixed << max << endl;
    return 0;
}
// N = 100, N^2 = 10,000 組み合わせ全探索で行けるくね