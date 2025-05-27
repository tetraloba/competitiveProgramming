// 2024/02/26 12:32:12
// 
#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 998244353
using namespace std;
// a C b
long long C(int a, int b){

    return ans;
}
int main(){
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    int i = 0;
    while (M < K) {
        A[i] = M;
        K -= M;
        i++;
    }
    A[i] = K;
    int num_free = 0;
    while (true) {
        if (!A[i]) {
            if (!i) {
                break;
            }
            i--;
        }
        A[i]--;
        num_free++;
        // N - 1 - i 個の枠 +どこにも入れない1
        C(num_free + M - 1,num_free);
        
    }

    for (int k = N; k <= K; k++) {
        // k の作り方 k個の1をN個の枠に振り分ける.但し1<=1枠の個数<=M

    }


    return 0;
}
// 2 3 5
// 2 2 3
// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1
// oo|| 4 C 2 = 6
// oo|| 
