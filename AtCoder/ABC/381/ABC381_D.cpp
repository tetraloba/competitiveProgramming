// 2024/12/13 10:59:41
// 2024/12/13 11:33:27 AC.
#include <iostream>
#include <vector>
#include <set>
#define LEN (r - l  + 1)
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    int ans = 0;
    set<int> st;
    int l = 0, r = 1;
    while (r < N) {
        if (A[r - 1] == A[r]) {
            if (st.count(A[r])) {
                while (A[l] != A[r]) {
                    st.erase(A[l]);
                    l++;
                }
                while (A[l] == A[r] && l < r - 1) {
                    l++;
                }
            }
            st.insert(A[r]);
            ans = max(ans, LEN);
        } else if (LEN <= 2 || A[r - 2] != A[r - 1]) {
            st.clear();
            l = r;
        }
        // cerr << l << ' ' << r << ' ' << ans << endl;
        r++;
    }
    cout << ans << endl;
    return 0;
}
/*
1, 2 の時点で1以前はもう無視できる
1, 1, 1 の時点で最初の1以前は無視できる
1, 1, 2, 2, 3, 3, 1 の時点で1, 1以前は無視できる (2024/12/13 11:03:12)
queueだなあ。(2024/12/13 11:08:04)
sample弱すぎるンゴ…(2024/12/13 11:24:08)

12
1 1 2 2 3 3 1 2 2 2 3 3
*/
/*
ACなのか。あまり自信ないんだが・・・
公式解説の解法2に近いんだろうが、解説はlast[]で最終出現位置を記録してあるのかな。
まあ↑の実装のように尺取法よろしくl++で追いかけていってもO(N)でしょう。
*/
