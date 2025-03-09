// 2025/03/09 20:48:05
// 2025/03/09 21:20:56 AC.
#include <iostream>
#include <vector>
#define NUM 998244353
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> AB(N);
    for (auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }
    vector<pair<int, int>> cnt(N);
    cnt[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        cnt[i].first += (AB[i].first == AB[i - 1].first ? 0 : cnt[i - 1].first);
        cnt[i].first %= NUM;
        cnt[i].second += (AB[i].second == AB[i - 1].first ? 0 : cnt[i - 1].first);
        cnt[i].second %= NUM;
        cnt[i].first += (AB[i].first == AB[i - 1].second ? 0 : cnt[i - 1].second);
        cnt[i].first %= NUM;
        cnt[i].second += (AB[i].second == AB[i - 1].second ? 0 : cnt[i - 1].second);
        cnt[i].second %= NUM;
    }
    cout << (cnt[N - 1].first + cnt[N - 1].second) % NUM << endl;
    return 0;
}
/*
計算問題やなあ。
隣り合うやつが同じだった場合だけを考えれば良いと。(2025/03/09 20:50:13)
カードiがカードi-1と両面とも異なるならx2
片面一致なら？両面一致なら？で計算していけばO(N)で求まるか？(2025/03/09 20:51:25)
片面一致: 
1,2  2,3  3,1  1,3
1,1  1,2  1,3  3,1

違うなあ。裏返す組み合わせかああ(2025/03/09 21:04:47)
1,2  2,3  3,1  1,3
0,1  0,2  2,1  2,2

1,2  4,2  3,4
0,1  1,1  2,2

1,5  2,6  3,7  4,8
1,1  2,2  4,4  8,8

1,2  4,2  3,4
1,1  2,1  3,1

1,2  3,4  1,2  3,4  1,2   3,1   3,1   1,3
1,1  2,2  4,4  8,8 16,16 32,16 16,32 32,16
*/
/*
いや最初ので合ってるじゃん(2025/03/09 21:21:31)
*/
