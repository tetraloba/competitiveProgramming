// 2025/12/12 21:35:33
// 2025/12/12 21:42:28 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;

    map<int, int> cnt;
    for (int i = 1; i <= N; i++) {
        cnt[i] = 1;
    }
    
    auto itr = cnt.begin();
    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        int updated = 0;
        while (itr != cnt.end() && itr->first <= x) {
            updated += itr->second;
            itr++;
        }
        cnt[y] += updated;
        cout << updated << endl;
    }

    return 0;
}
/*
2025/12/12 21:37:12
カウントしてソートして(mapで良い)、前から詰めていけば良いわけね。
2025/12/12 21:37:52
いや、1つずつで並んでいるのか。やることは同じか？
*/
/*
2025/12/12 21:43:44
解説を読んで。
まあバージョンが並んでいるので、mapじゃなくて配列でもできましたよと。
*/
