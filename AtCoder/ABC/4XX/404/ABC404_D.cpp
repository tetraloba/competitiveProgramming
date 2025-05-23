// 2025/05/24 07:45:56
// 2025/05/24 08:40:13 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
long long func(vector<int>& zoo2price, vector<vector<int>>& zoo2animals, vector<int> zoo_cnt, vector<int> animal_cnt, int tgt_zoo, long long price) {
    if (tgt_zoo == zoo2price.size()) {
        for (int i : animal_cnt) {
            if (i < 2) {
                return INT64_MAX;
            }
        }
        return price;
    }

    long long res = INT64_MAX; // 最安値
    /* tgt_zoo に 0回 行く */
    res = min(res, func(zoo2price, zoo2animals, zoo_cnt, animal_cnt, tgt_zoo + 1, price));
    /* tgt_zoo に 1回 または 2回 行く */
    for (int times = 0; times < 2; times++) {
        zoo_cnt[tgt_zoo]++;
        for (int i : zoo2animals[tgt_zoo]) {
            animal_cnt[i]++;
        }
        price += zoo2price[tgt_zoo];
        res = min(res, func(zoo2price, zoo2animals, zoo_cnt, animal_cnt, tgt_zoo + 1, price));
    }
    return res;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    for (int &c : C) {
        cin >> c;
    }
    vector<vector<int>> A(M);
    for (auto &v : A) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            a--;
            v.push_back(a);
        }
    }
    /* debug */
    // cerr << 'A' << endl;
    // for (auto v : A) {
    //     for (int i : v) {
    //         cerr << i << ' ';
    //     }
    //     cerr << endl;
    // }

    vector<vector<int>> zoo_animals(N);
    for (int m = 0; m < M; m++) {
        for (int i : A[m]) {
            zoo_animals[i].push_back(m);
        }
    }
    vector<int> zoo_cnt(N), animal_cnt(M);
    cout << func(C, zoo_animals, zoo_cnt, animal_cnt, 0, 0) << endl;
    return 0;
}
/*
DPで解けるのか？
制約的にもDPっぽいなあ(2025/05/24 07:50:06)
入力例にはないけど1,2 2,3 3,1を見れる動物園があって、1回ずつ行けば良い、みたいなパターンもあるよね。(2025/05/24 07:51:33)
3 3
1 1 1
2 1 2
2 2 3
2 1 3
みたいな感じか。
100種類を2回ずつ見る、いや10園を2回ずつ訪れるのが最大か。(2025/05/24 07:54:21)
状態を要素数100の配列で管理したDPで20 * 100 * 100くらいかなあ。(2025/05/24 08:03:59)
いや、状態が重複しないとDPによる計算量削減が効かないのか。意味ないな(2025/05/24 08:06:42)
ん、違う違う、違うな。
20個の動物園があって、行く行かないの1/0だとすると、2^20で1048576通りか。重複あるが。(2025/05/24 08:10:35)
というか0/1/2回行くの3通りが10園だから3^10 = 59049通りか。それぞれについて100種類の動物の状態を見れば良いから全探索で間に合うわけね。(2025/05/24 08:12:17)
でどうやって書くんだ？バイナリしか書いたことないンゴ・・・(2025/05/24 08:13:20)
再帰なら書ける。ということはスタック使えば書けなくはないか。(2025/05/24 08:14:04)
それか久々に再帰書くか。(2025/05/24 08:15:19)
*/
