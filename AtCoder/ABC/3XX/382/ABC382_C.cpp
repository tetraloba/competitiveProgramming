// 2024/12/12 08:14:10
// 2024/12/12 08:22:49 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<pair<int, int>> B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }

    sort(B.rbegin(), B.rend());
    vector<int> BtoA(M, -1); // i番目の寿司(B[].secondに相当)を食べるA
    int b = 0;
    for (int i = 0; i < N; i++) {
        while (b < M && A[i] <= B[b].first) {
            BtoA[B[b].second] = i + 1;
            b++;
        }
    }

    for (int ans : BtoA) {
        cout << ans << endl;
    }
    return 0;
}
/*
人は消えないし寿司の順番は関係ないから、寿司を大きい順に並べておいて一気に流せば良い。(2024/12/12 08:16:57)
*/
/*
解説は 1 <= Ai, Bi <= 2e5 に注目したのか。面白い。
*/
