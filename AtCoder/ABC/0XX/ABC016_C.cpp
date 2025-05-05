// 2025/05/05 21:42:41
// 2025/05/05 21:52:08 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        set<int> friends(G[i].begin(), G[i].end());
        set<int> friend_of_friends;
        for (int f : friends) {
            for (int fof : G[f]) {
                friend_of_friends.insert(fof);
            }
        }
        set<int> ans;
        set_difference(friend_of_friends.begin(), friend_of_friends.end(), friends.begin(), friends.end(), inserter(ans, ans.end()));
        ans.erase(i);
        cout << ans.size() << endl;
    }
    return 0;
}
