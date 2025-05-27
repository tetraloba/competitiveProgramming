// 2023/06/02 22:44:34
// 2023/06/02 22:56:28 WA.
// 2023/06/02 23:05:05 WA.
// 2023/06/02 23:09:16 AC.
// 2023/06/02 23:45:14 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> target;
    for (int i = 0; i < N; i++) {
        target.insert(A[i] + X);
        target.insert(A[i] - X);
    }
    for (int i = 0; i < N; i++) {
        if (target.count(A[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
// ソートして二分探索すればnlog(n)*2で行けそうだけど？
// あ、絶対差じゃないのか。大 - 小 とは限らないのか。逆verもう一回やっても間に合うかな？(笑)
// set使ったverってこれで良いのか…？