// 2023/06/03 00:25:08
// 2023/06/03 00:48:14 TLE
// 2023/06/03 00:56:28 TLE
// 2023/06/03 01:00:18 TLE
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
    vector<vector<int>> paths(N + 1); // paths[a] は Xからaまでの単純パス(配列)
    paths[X].push_back(X);
    stack[stack_size++] = X;
    while (1) {
        int tgt = stack[--stack_size];
        for (int i : G[tgt]) {
            cout << "debug: " << tgt << ':' << i << endl;
            if (i == *(paths[tgt].rbegin() + 1)) {
                cout << "debug: " << i << ' ' << *(paths[tgt].rbegin() + 1) << endl;
                continue;
            }
            paths[i] = paths[tgt];
            paths[i].push_back(i);
            stack[stack_size++] = i;
            if (i == Y) {
                for (int i : paths[Y]) {
                    cout << i << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
// 適当に根を決めて、祖先リストを出せば必ずどこかから一致するよね。
// いや祖先を判定できないわ。20万個か。普通に全探索しちゃダメ？