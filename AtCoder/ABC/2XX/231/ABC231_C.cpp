// 2024/07/06 13:28:09
// 2024/07/06 13:32:15 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << N - (lower_bound(A.begin(), A.end(), x) - A.begin()) << endl;
    }
    return 0;
}
/*
普通に、ソートして二分探索かな。
N = 5
0 1 2 3 4
*/
/*
解説にはBinaryTrie木を使った実装も有る。
気が向いたら勉強しよう。(2024/07/06 14:02:04)
*/
