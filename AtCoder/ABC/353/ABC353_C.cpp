// 2024/06/30 12:01:39
// 2024/06/30 12:36:30 17WA
// 2024/06/30 12:42:27 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#define LIM 100000000
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    sort(A.begin(), A.end());
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (long long)A[i] * (N - 1);
        int border = LIM - A[i];
        int idx = lower_bound(A.begin(), A.end(), border) - A.begin();
        if (i < idx) {
            ans -= (long long)LIM * (N - idx);
        } else {
            ans -= (long long)LIM * (N - (i + 1));
        }
    }

    cout << ans << endl;
    return 0;
}
/*
組み合わせ N C 2
並び順は無視できる
昇順にならべて…
Aは10^8を超えないので、f(Ai,Aj)は10^8を引くか引かないかの二択


*/
