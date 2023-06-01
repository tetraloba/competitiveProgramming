//2022/09/01 07:33:37
//2022/09/01 07:40:53 WA
//2022/09/01 07:58:43 WA
//2022/09/01 07:59:36 WA
//ABC224_C - Triangle?
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
    vector<Pos> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (((double)p[i].y - p[j].y) / ((double)p[i].x - p[j].x) != ((double)p[j].y - p[k].y) / ((double)p[j].x - p[k].x)) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
// NC3 - 直線となる選び方
// そんなんするより数え上げたほうが良いかな
// 300^3 90,000 300 27,000,000
// 3点が一直線上にあるか。2組の2点を通る直線の傾きが同じ？？
// あーマイナスで間違える可能性？？ いやマイナス/マイナスで直る。
// -10^9 - 10^9とかでオーバーフローするのか。
// 最初からdoubleでも良さそう。精度は知らん。