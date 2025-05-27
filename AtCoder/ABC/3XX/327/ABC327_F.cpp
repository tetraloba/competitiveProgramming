// 2023/11/04 22:03:45
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, D, W;
    cin >> N >> D >> W;
    vector<int> T(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> X[i];
    }
    cout <<  << endl;
    return 0;
}
// S - 0.5, ~ S + D - 0.5
// L - 0.5 <= x <= L + W - 0.5
// 平面上の点を長方形で覆う問題で良いのかな。
// 範囲だから尺取法とか累積和とかの類な気はするが・・・
// 2次元尺取法とかないのか？？
