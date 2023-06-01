//2022/08/14 07:38:32
//愚直にシミュレーションすると余裕でTLE
//ボトルネックから計算すればええだけやんｗｗｗ
//2022/08/14 09:32:17 WA
#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 5
using namespace std;
int main(){
    long long N;
    vector<long long> A(NUM);
    cin >> N;
    for (int i = 0; i < NUM; i++) {
        cin >> A[i];
    }
    cout << N / *min_element(A.begin(), A.end()) - (N % *min_element(A.begin(), A.end()) ? 0 : 1) + NUM << endl;
   return 0;
}