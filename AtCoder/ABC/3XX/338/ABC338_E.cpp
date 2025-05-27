// 2024/04/08 19:42:46
// 2024/04/08 20:03:09 6WA
// 2024/04/08 20:27:25 AC.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> partner(2 * N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        partner[a] = b;
        partner[b] = a;
    }
    stack<int> stk;
    stk.push(0);
    for (int i = 1; i < 2 * N; i++) {
        // if (stk.empty()) {
        //     cout << "empty ";
        // } else {
        //     cout << stk.top() << ' ';
        // }
        // cout << i << '(' << partner[i] << ')' << endl;
        if (!stk.empty() && partner[i] == stk.top()) {
            stk.pop();
        } else {
            stk.push(i);
        }
    }
    cout << (stk.empty() ? "No" : "Yes") << endl;
    return 0;
}
/*
2N個の点でN個の弦なら、交差しない張り方なんて数えるほどしかなくない？(2024/04/08 19:45:01)
全部平行に張るってことでしょ。後はそれが頂点番号的にどういう法則性になるのかを考えるだけ。ほぼICPC。(2024/04/08 19:46:05)

N=2のとき
    1-2 3-4
    1-3 はx
    1-4 2-3
N=3のとき
    1-2 3-6 4-5
    1-3 x
    1-4 2-3 5-6
    1-5 x
    1-6 2-5 3-4
    間が偶数ならOKってところかな。
N=4のとき
    1-2 3-8 4-7 5-6
    1-3 x
    1-4 2-3 5-8 6-7
    ...
1の相手を見て、間が奇数ならYes
偶数の時、1とその相手から逆回りに一つずつ動いていったペアの内、ひとつでも結ばれていないものが有ればYes
さもなくばNo (2024/04/08 19:53:14)

まあ 28AC 6WA ですよと。

ああ、
N=3のとき
    1-2 3-4 5-6 も有るやん・・・
0~partner[0]の間にボッチがいなければ良い。
累積和的なやつでO(N)に落とす流れかな。(2024/04/08 20:15:34)
いや、スタックで消していけば良いのか？
あー括弧の対応と考えれば良かったのか…(2024/04/08 20:21:40)
*/
