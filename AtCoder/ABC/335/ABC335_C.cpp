// 2024/02/13 00:32:53
// 2024/02/13 00:59:53 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N, Q;
map<char, pair<int,int>> DIR4 = {{'R',make_pair(1,0)},
                                {'L',make_pair(-1,0)},
                                {'U',make_pair(0,1)},
                                {'D',make_pair(0,-1)}};
int next(int i, int d){
    return (N + i - d) % N;
}
int main(){
    cin >> N >> Q;
    vector<pair<int, int>> D(N);
    for (int i = 0; i < N; i++) {
        D[i].first = i + 1;
        D[i].second = 0;
    }
    int n = 0; // 頭を表すindex
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            char C;
            cin >> C;
            D[next(n, 1)] = make_pair(D[n].first + DIR4[C].first, D[n].second + DIR4[C].second);
            n = next(n, 1);
        } else {
            int p;
            cin >> p;
            p--;
            cout << D[next(n, -p)].first << ' ' << D[next(n, -p)].second << endl;
        }
    }
    return 0;
}
// リングバッファ作れば良いってことね。
