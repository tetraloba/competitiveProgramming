//2023/04/05 23:19:47
//2023/04/05 23:21:59 上手いこと判定する手はないものか・・・
//2023/05/14 09:06:21 まあ普通にsetで良いんじゃ？？
// 2023/05/14 09:10:56 WA
// 2023/05/14 09:42:23 AC. 洗濯しつつ()
#include <iostream>
// #include <vector>
#include <set>
#include <map>
using namespace std;
map<char, int> dist{{'R', 0}, {'L', 1}, {'U', 2}, {'D', 3}};
pair<int, int> dist4[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
int main(){
    int N;
    pair<int, int> current(make_pair(0, 0));
    set<pair<int, int>> log;
    log.insert(current);
    cin >> N;
    char move;
    for (int i = 0; i < N; i++) {
        cin >> move;
        current = make_pair(current.first + dist4[dist[move]].first, current.second + dist4[dist[move]].second);
        if (log.find(current) != log.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        log.insert(current);
    }
    // for (pair<int, int> e : log) {
    //     cout << "<" << e.first << ", " << e.second << "> ";
    // }
    // cout << endl;
    cout << "No" << endl;
    return 0;
}