// 2023/06/06 23:22:38
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> P(N), Q(N, 0);
    for (int i = 0; i < K - 1; i++) {
        cin >> P[i];
    }
    make_heap(P.begin(), P.end());
    for (int i = K - 1; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (P[K - 1] <= tmp) {
            P.push_back(tmp);
            push_heap(P.begin(), P.end());
        }
    }
    sort(P.begin(), P.end());
    cout <<  << endl;
    return 0;
}
// ヒープ使いたいんだけど…min heapの作り方が分からん・・・