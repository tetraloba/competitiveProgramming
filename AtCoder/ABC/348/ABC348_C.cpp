// 2024/04/06 21:06:21
// 2024/04/06 21:10:01 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    map<int, int> min_A;
    for (int i = 0; i < N; i++) {
        int A, C;
        cin >> A >> C;
        if (min_A[C] == 0 || A < min_A[C]) {
            min_A[C] = A;
        }
    }
    int max = 0;
    for (auto [k, v] : min_A) {
        if (max < v) {
            max = v;
        }
    }
    cout << max << endl;
    return 0;
}
/*
各色について最小値を求めて、それら最小値の最大値が答。
*/
