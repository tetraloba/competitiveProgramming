//2022/08/04 18:10:05
//2022/08/04 18:27:36 TLE
//2022/08/04 18:32:49 WA
//2022/08/04 19:07:07 AC.
#include <iostream>
using namespace std;
int main(){
    int N, a[500000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == i + 1) { //a[i] < a[j]
            cnt1++;
        } else if (a[a[i] - 1] == i + 1) { //a[j] < a[i]
            // cout << i << ' ' << a[i] - 1 << endl;
            cnt2++;
        }
    }
    cout << (long long)cnt1 * (cnt1 - 1) / 2 + cnt2 / 2 << '\n'; //cnt1 C 2 + cnt2 / 2
    return 0;
}
//a[i] < a[j]はインデックスと要素が一致するやつを数え上げて組み合わせ
//a[j] < a[i]はiからjを求めて確かめる。
//j = a[i] - 1
//i != j => i != a[i] - 1 => a[i] != i + 1
//500000, 500000 250,000,000,000