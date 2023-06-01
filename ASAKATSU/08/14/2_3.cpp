//2022/08/14 07:31:13
//2022/08/14 08:53:45 WA. 配列の数とか間違っているかも。
//謎条件… mapか何かでハッシュ化するのが正解？
//2022/08/14 09:17:24 AC. 最後の処理順が違ったわ。
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    /* input */ {
        map<int, int> m;
        for (int i = 0; i < N; i++) {
            cin >> c[i];
            m.insert(make_pair(c[i], i));
        }
        for (int i = 0; i < N; i++) {
            c[i] = m.at(c[i]); //色を0~N-1の値(id)に置き換え
        }
    }
    set<int> s;
    vector<int> cnt(N);
    for (int i = 0; i < K; i++) {
        s.insert(c[i]);
        cnt[c[i]]++;
    }
    int val = s.size();
    int max = val; //マックスバリュ()
    for (int i = K; i < N; i++) {
        // cout << val << endl;
        // for (int j = 0; j < N; j++) {
        //     cout << cnt[j] << ' ';
        // }
        // cout << endl;
        cnt[c[i]]++;
        if (cnt[c[i]] == 1) {
            val++;
        }
        cnt[c[i - K]]--;
        if (cnt[c[i - K]] == 0) {
            val--;
        }
        if (max < val) {
            max = val;
        }
    }
    cout << max << endl;
    return 0;
}