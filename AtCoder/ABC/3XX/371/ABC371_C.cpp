// 2024/11/30 12:18:55
// 2024/11/30 12:57:25 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    /* input */
    int N;
    cin >> N;
    vector<vector<bool>> G(N, vector<bool>(N)), H(N, vector<bool>(N)); // グラフ。8x8の隣接行列で良いか…
    int Mg, Mh;
    cin >> Mg;
    for (int i = 0; i < Mg; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u][v] = true;
        G[v][u] = true;
    }
    cin >> Mh;
    for (int i = 0; i < Mh; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        H[a][b] = true;
        H[b][a] = true;
    }
    vector<vector<int>> price(N, vector<int>(N)); // price[i][j] 頂点i,j間の辺を置き換えるコスト
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a;
            cin >> a;
            price[i][j] = a;
        }
    }

    /* debug */
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cerr << price[i][j] << '\t';
    //     }
    //     cerr << endl;
    // }

    vector<int> vh2g(N); // Hの頂点番号をGの頂点番号に対応させるマップ vertex H to G
    for (int i = 0; i < N; i++) {
        vh2g[i] = i;
    }

    /* process */
    int ans = 64e6; // 8x8x10^6 <= 32bit
    do {
        int p = 0; // price
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (H[i][j] ^ G[vh2g[i]][vh2g[j]]) {
                    p += price[i][j];
                }
            }
        }
        ans = min(ans, p);
    } while (next_permutation(vh2g.begin(), vh2g.end()));

    /* output */
    cout << ans << endl;
    return 0;
}
/*
頂点の並び替えは8! = 8 7 6 5 4 3 2 1 = 40320
これを全探索して、それぞれについて価格を求める感じか。 (2024/11/30 12:23:13)
*/

