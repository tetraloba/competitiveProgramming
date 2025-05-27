// 2024/03/02 19:16:22
// 2024/03/02 20:30:18 AC.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define NUM 3
#define PATTERN 362880 // 9!
using namespace std;
int main(){
    int c[NUM][NUM];
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            cin >> c[i][j];
        }
    }
    vector<int> seq = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int num_gakkari = 0;
    do {
        int d[NUM][NUM] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        // /* debug */
        // cout << "seq(";
        // for (int o : seq) cout << o << ' ';
        // cout << "): ";
        bool gakkari = false;
        for (int o : seq) {
            int o_i = o / 3, o_j = o % 3;
            d[o_i][o_j] = c[o_i][o_j];
            if (d[o_i][0] && d[o_i][1] && d[o_i][2]) { // 横が出揃っているなら
                switch (o_j) {
                    case 0:
                        if (d[o_i][1] == d[o_i][2]) {
                            gakkari = true;
                        }
                        break;
                    case 1:
                        if (d[o_i][0] == d[o_i][2]) {
                            gakkari = true;
                        }
                        break;
                    case 2:
                        if (d[o_i][0] == d[o_i][1]) {
                            gakkari = true;
                        }
                        break;
                }
            }
            if (d[0][o_j] && d[1][o_j] && d[2][o_j]) { // 縦が出揃っているなら
                switch (o_i) {
                    case 0:
                        if (d[1][o_j] == d[2][o_j]) {
                            gakkari = true;
                        }
                        break;
                    case 1:
                        if (d[0][o_j] == d[2][o_j]) {
                            gakkari = true;
                        }
                        break;
                    case 2:
                        if (d[0][o_j] == d[1][o_j]) {
                            gakkari = true;
                        }
                        break;
                }
            }
            if (o_i == o_j && d[0][0] && d[1][1] && d[2][2]) { // バックスラッシュな斜め内で、それが出揃っているなら
                switch (o_i) {
                    case 0:
                        if (d[1][1] == d[2][2]) {
                            gakkari = true;
                        }
                        break;
                    case 1:
                        if (d[0][0] == d[2][2]) {
                            gakkari = true;
                        }
                        break;
                    case 2:
                        if (d[0][0] == d[1][1]) {
                            gakkari = true;
                        }
                        break;
                }
            }
            if (o_i + o_j == NUM - 1 && d[0][2] && d[1][1] && d[2][0]) { // スラッシュな斜め内で、それが出揃っているなら
                switch (o_i) {
                    case 0:
                        if (d[1][1] == d[2][0]) {
                            gakkari = true;
                        }
                        break;
                    case 1:
                        if (d[0][2] == d[2][0]) {
                            gakkari = true;
                        }
                        break;
                    case 2:
                        if (d[0][2] == d[1][1]) {
                            gakkari = true;
                        }
                        break;
                }
            }
            if (gakkari) {
                // cout << "gakkari at " << o << endl; // debug
                break;
            }
        }
        if (gakkari) {
            num_gakkari++;
        }
    } while (next_permutation(seq.begin(), seq.end()));
    cout << setprecision(10) << (double)(PATTERN - num_gakkari) / PATTERN << endl;
    return 0;
}

/*
ICPCみたいな問題だな。
全ての開き方は9!通り。
一列が独立している時
1 1 2
がっかりする確率は最後に開くのが2である時なので1/3 (入力例1参照)

交わっている時
    どちらも1つの方が交わっている時
        1 2 2
        3
        3
        全部で5!=120通り
        1 - 4!=24通り
        x 1 - 2(x) * 2(2つの内1つ) = 4通り
        3 2 1 - 2(3か2) * 2(先に選んだ2つの内一つ) * 2(選んでない方の2つの内1つ) * 2!(残りの1つずつ)=12通り
        従って40/120=1/3 => がっかりするのは2/3
    どちらも2つのほうが交わっている時
        1 1 2
        1
        3
        wakaran
全部で9! = 9 8 7 6 5 4 3 2 1 = 504 * 720 = 360000 + 2880 = 362880
全探索したほうが早くないか？(2024/03/02 19:32)
*/
/*
解説を読んで。
確認すべき縦・横・斜めの8通りをそれぞれ配列で管理している。DIR8配列なんかと同じ発想だな。
実際に開けていくシミュレーションをしなくても、3個のマスをどの順で開けたかは判定できる。。。
開ける順番を表すorder[]配列は、i番目に開ける要素をorder[i]としているのではなく、iの要素を開ける順番をorder[i]としているのか。
i番目にorder[i]を開けるのではなくiをorder[i]番目に開ける。
なるほど勉強になるなあ。
*/