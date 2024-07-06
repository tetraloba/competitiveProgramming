// 2024/07/06 12:58:44
// 2024/07/06 13:23:19 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/* 2つのグラフが同一ならtrue */
bool graphcmp(vector<set<int>>& G1, vector<set<int>>& G2){
    if (G1.size() != G2.size()) {
        return false;
    }
    const int N = G1.size();
    for (int i = 0; i < N; i++) {
        if (G1[i].size() != G2[i].size()) {
            return false;
        }
        auto itr1 = G1[i].begin(), itr2 = G2[i].begin();
        while (itr1 != G1[i].end()) {
            if (*itr1 != *itr2) {
                return false;
            }
            itr1++; itr2++;
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> T(N), A(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        T[a].insert(b);
        T[b].insert(a);
    }
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        A[c].insert(d);
        A[d].insert(c);
    }

    vector<int> P;
    for (int i = 0; i < N; i++) {
        P.push_back(i);
    }

    do {
        /* グラフAを順列PによってグラフBに変換 */
        vector<set<int>> B(N);
        for (int i = 0; i < N; i++) {
            for (int e : A[i]) {
                B[P[i]].insert(P[e]);
            }
        }
        /* グラフTとグラフBを比較 */
        if (graphcmp(T, B)) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(P.begin(), P.end()));

    cout << "No" << endl;
    return 0;
}
/*
愚直に順列を全探索すると…？
8! = 8 7 6 5 4 3 2 1 = 56 * 720 = 40320
間に合いそうな気がしなくもない。
*/
