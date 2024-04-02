// 2024/04/03 07:51:57
// 2024/04/03 08:16:21 AC.
// ABC294_E - 2xN Grid
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    long long L;
    int N1, N2;
    cin >> L >> N1 >> N2;
    stack<pair<int, long long>> stk1, stk2;
    for (int i = 0; i < N1; i++) {
        long long v, l;
        cin >> v >> l;
        stk1.push({v, l});
    }
    for (int i = 0; i < N2; i++) {
        long long v, l;
        cin >> v >> l;
        stk2.push({v, l});
    }
    long long ans = 0;
    long long i1 = 0, i2 = 0;
    int v1, v2;
    long long l1, l2;
    while (!stk1.empty() || !stk2.empty()) {
        long long i1pre = i1, i2pre = i2;
        if (i1pre <= i2pre) {
            auto tgt = stk1.top(); stk1.pop();
            v1 = tgt.first;
            l1 = tgt.second;
            i1 += l1;
        }
        if (i2pre <= i1pre) {
            auto tgt = stk2.top(); stk2.pop();
            v2 = tgt.first;
            l2 = tgt.second;
            i2 += l2;
        }
        if (v1 == v2) {
            ans += min(l2 - max(i2 - i1, 0ll), l1 - max(i1 - i2, 0ll));
        }
    }
    cout << ans << endl;
    return 0;
}
/*
1 2
3 2
2 3
3 1

1 4
2 1
3 3

1 1 3 3 2 2 2
1 1 1 1 2

3 2 2 2 3 3
3 3 3 2 1 1 1 1

*/
