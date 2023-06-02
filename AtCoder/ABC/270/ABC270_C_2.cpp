// 2023/06/03 00:25:08
// 2023/06/03 00:48:14 TLE
// 2023/06/03 00:56:28 TLE
// 2023/06/03 01:00:18 TLE
// 2023/06/03 01:28:58 AC.
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<set<int>> G(N + 1);
    for (int i = 1; i <= N - 1; i++) {
        int U, V;
        cin >> U >> V;
        G[U].insert(V);
        G[V].insert(U);
    }
    vector<int> stack(N);
    int stack_size = 0;
    vector<int> path_next(N + 1); // path_next[a] は aからYまでの単純パスにおける、aの次の要素
    path_next[Y] = 0; // 終点
    stack[stack_size++] = Y;
    while (1) {
        int tgt = stack[--stack_size];
        for (int i : G[tgt]) {
            // cout << "debug: " << tgt << ':' << i << endl;
            if (i == path_next[tgt]) {
                // cout << "debug: " << i << ' ' << path_next[tgt] << endl;
                continue;
            }
            path_next[i] = tgt;
            stack[stack_size++] = i;
            if (i == X) {
                int p = X;
                while (p) {
                    cout << p << ' ';
                    p = path_next[p];
                }
                cout << endl;
                return 0;
            }
        }
    }
}
// 適当に根を決めて、祖先リストを出せば必ずどこかから一致するよね。
// いや祖先を判定できないわ。20万個か。普通に全探索しちゃダメ？