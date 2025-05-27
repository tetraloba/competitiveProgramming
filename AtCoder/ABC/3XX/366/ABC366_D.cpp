// 2024/11/29 18:47:03
// 2024/11/29 20:13:02 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<vector<long long>>> vvv(N + 1, vector<vector<long long>>(N + 1, vector<long long>(N + 1)));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                cin >> vvv[i][j][k];
            }
        }
    }

    /* 累積和化 */
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                vvv[i][j][k] += vvv[i][j][k - 1];
            }
        }
    }
    /* debug */
    // cerr << "-- debug1 --" << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         for (int k = 0; k <= N; k++) {
    //             cerr << vvv[i][j][k] << '\t';
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                vvv[i][j][k] += vvv[i][j - 1][k];
            }
        }
    }
    /* debug */
    // cerr << "-- debug2 --" << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         for (int k = 0; k <= N; k++) {
    //             cerr << vvv[i][j][k] << '\t';
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                vvv[i][j][k] += vvv[i - 1][j][k];
            }
        }
    }
    /* debug */
    // cerr << "-- debug3 --" << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         for (int k = 0; k <= N; k++) {
    //             cerr << vvv[i][j][k] << '\t';
    //         }
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }

    /* クエリ */
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--; ly--; lz--;
        long long ans = ((vvv[rx][ry][rz] - vvv[lx][ry][rz]) - (vvv[rx][ly][rz] - vvv[lx][ly][rz]))
                      - ((vvv[rx][ry][lz] - vvv[lx][ry][lz]) - (vvv[rx][ly][lz] - vvv[lx][ly][lz]));
        cout << ans << endl;
    }
    return 0;
}
/*
えーなにこれ、頑張って累積和？(2024/11/29 18:48:31)
1 2 3
4 5 6
7 8 9
5 + 6 + 8 + 9 = 28

1 3 6
4 9 15
7 15 24
(15 - 4) + (24 - 7) = 28

 1  3  6
 5 12 21
12 27 45
(45 - 12) - (6 - 1) = 28

みたいなことか。
これをさらに３次元に拡張すると・・・(2024/11/29 18:54:48)

3

1 2 3
4 5 6
7 8 9

10 11 12
13 14 15
16 17 18

19 20 21
22 23 24
25 26 27
*/
