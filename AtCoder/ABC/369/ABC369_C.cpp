// 2024/11/24 14:42:53
// 2024/11/24 15:23:40 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) {
        cin >> a;
    }
    long long ans = 0;
    int l = 0, r = l;
    while (r < N) {
        ans++;
        r++;
        if (!(r < N)) {
            break;
        }
        int d = A[r] - A[l];
        while (r < N && A[r] - A[r - 1] == d) {
            ans += r - l + 1;
            r++;
        }
        l = r - 1;
        r = l;
        ans--;
    }
    cout << ans << endl;
    return 0;
}
/*
1 -> 1
2 -> 2 + 1
3 -> 3 + 2 + 1
4 -> 4 + 3 + 2 + 1

1 2 3 5
*/
/*
流石にもうちょっと美しく書けるだろうという気はする。
*/
