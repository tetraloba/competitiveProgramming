// 2024/03/16 18:08:11
// 2024/03/16 18:45:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (string &s : S) {
        cin >> s;
    }
    int ans = 0;
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            int h = i, w = j;
            if (S[h][w] == '#') {
                continue;
            }
            bool flag = true;
            for (char c : T) {
                switch (c) {
                    case 'L': w--; break;
                    case 'R': w++; break;
                    case 'U': h--; break;
                    case 'D': h++; break;
                }
                if (S[h][w] == '#') {
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
################
##..##.#..####.#
###.#..#.....#.#
#..##..#####.###
#...#..#......##
###.##.#..#....#
##.#####....##.#
###.###.#.#.#..#
######.....##..#
#...#.#.######.#
##..###..#..#.##
#...#.#.#...#..#
################

ULURDLURD
..
..
#.
全探索500*500*500のTLE以外見えないんだが
125,000,000 = 10^8 なら間に合うのか
*/
/*
10^8が通るパターンを知らなかったよ・・・
より高速な解法は、工夫してbitsetとシフト演算に落とし込むことで高速化しているらしいが、分からん…
*/
