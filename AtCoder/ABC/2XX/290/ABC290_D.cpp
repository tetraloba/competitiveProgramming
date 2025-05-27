// 2024/05/03 15:05:58
// 
#include <iostream>
#include <vector>
using namespace std;
int query(int N, int D, int K){
    D %= N + 1;
    vector<bool> done(D);
    int start = 0;
    while (true) {
        done[start] = true;
        int num = (N - start) / D + 1;
        if (K <= num) {
            return start + D * (K - 1);
        }
        K -= num;
        start = (start + D * num) % N;
        while (done[start]) {
            start = (start + 1) % D;
        }
    }
}
int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, D, K;
        cin >> N >> D >> K;
        cout << query(--N, D, K) << endl;
    }
    return 0;
}
/*
4 3 3
4 3 1
start 2

4 2
0 2 4
1 3

*/
