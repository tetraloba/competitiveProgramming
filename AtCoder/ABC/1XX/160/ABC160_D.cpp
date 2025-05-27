// 2024/10/11 11:04:31
// 
#include <iostream>
#include <vector>
using namespace std;

int N, X, Y;

int next(int i, bool reverse) {
    return reverse ? (i - 1 + N) % N : (i + 1) % N;
}

int diff(int a, int b) {
    return max(a - b, b - a);
}

int main(){
    cin >> N >> X >> Y;
    
    /* X < Y, X = 0に正規化 */
    Y = diff(X, Y);
    X = 0;

    vector<vector<int>> vv(N, vector<int>(4, -1));
    for (int r = 0; r < 4; r++) {
        bool reverse = r % 2;
        int tgt = r / 2 ? Y : 0;
        vv[tgt][r] = 1;
        /* O(N) */
        int i = 1;
        while (true) {
            tgt = next(tgt, reverse);
            if (vv[tgt][r] != -1) {
                break;
            }
            vv[tgt][r] = i + 1;
            i++;
        }
    }

    /* O(N^2) */
    vector<int> K(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int min_dist = N;
            for (int r = 0; r < 3; r++) {
                min_dist = min(diff(vv[i][r], vv[j][r]), min_dist);
            }
            K[min_dist]++;
        }
    }

    /* output */
    for (int i = 1; i <= N - 1; i++) {
        cout << K[i] << ' ';
    }
    cout << endl;
    return 0;
}
/*
全頂点間の最短距離を求めるってこと？ (2024/10/11 11:06:29)
N<=2000ならいけるか・・・
*/
