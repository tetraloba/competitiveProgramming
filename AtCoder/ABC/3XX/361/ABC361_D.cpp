// 2024/07/30 16:33:57
// 2024/07/30 17:39:16 AC.
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
string swap_string(string S, int index){
    char c1 = S[index], c2 = S[index + 1];
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '.') {
            S[i] = c1;
            S[i + 1] = c2;
            S[index] = '.';
            S[index + 1] = '.';
            return S;
        }
    }
}
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    set<string> cur;
    cur.insert(S + "..");
    map<string, int> mp;
    mp[S + ".."] = 0;
    int phase = 1;
    while (!cur.empty()) {
        set<string> next;
        for (string tgt : cur) {
            for (int i = 0; i < N + 1; i++) {
                if (tgt[i] == '.' || tgt[i + 1] == '.') {
                    continue;
                }
                string cand = swap_string(tgt, i);
                if (mp.count(cand)) {
                    continue;
                }
                mp[cand] = phase;
                next.insert(cand);
            }
        }
        cur = next;
        phase++;
    }
    // for (auto [k, v] : mp) {
    //     if (k[N] != '.' || k[N + 1] != '.') {
    //         continue;
    //     }
    //     cout << k << ':' << v << endl;
    // }
    cout << (mp.count(T + "..") ? mp[T + ".."] : -1) << endl;
    return 0;
}
/*
14
BBBWBWWWBBWWBW..
0-0--1--0--1-1..
WBWWBBWWWBWBBB

123..
..312

1234..
1..423
142..3
..2143
4321..

1234..
1..423
142..3
..2143
21..43
2143..

1234..
..3412
413..2
4..132
4321

1234..
    ..3412
        34..12
            3412..
        413..2
            4..132
                4321..
    1..423
        142..3
            ..2143
                21..43
                    2143..
                4321..
    12..34
        ..1234
            231..4
                2..314
                    2143..
            3412..

12345..
    ..34512
    1..4523
    12..534

うーん・・・
BFSしたら、間に合わない、のかね？(2024/07/30 16:59:47)
*/
/*
BFSで間に合ったああああ(歓喜)
*/
