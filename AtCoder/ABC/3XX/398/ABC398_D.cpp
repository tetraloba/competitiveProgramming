// 2025/03/22 21:17:58
// 2025/03/22 21:31:40 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, R, C;
    cin >> N >> R >> C;
    string S;
    cin >> S;

    pair<int, int> takahashi = {R, C}, smoke = {0, 0};
    set<pair<int, int>> smokes;
    smokes.insert(smoke);
    for (int i = 0; i < N; i++) {
        switch (S[i]) {
            case 'N':
                takahashi = {takahashi.first + 1, takahashi.second};
                smoke = {smoke.first + 1, smoke.second};
                break;
            case 'W':
                takahashi = {takahashi.first, takahashi.second + 1};
                smoke = {smoke.first, smoke.second + 1};
                break;
            case 'S':
                takahashi = {takahashi.first - 1, takahashi.second};
                smoke = {smoke.first - 1, smoke.second};
                break;
            case 'E':
                takahashi = {takahashi.first, takahashi.second - 1};
                smoke = {smoke.first, smoke.second - 1};
                break;
        }
        smokes.insert(smoke);
        cout << smokes.count(takahashi);
    }
    cout << endl;
    return 0;
}
/*
うーん，高橋くんと焚き火の位置を動かす方が楽そうだが？(2025/03/22 21:21:07)
*/
