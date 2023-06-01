//2022/08/19 11:36:09
//2022/08/19 11:40:50 TLE
#include <iostream>
#include <vector>
using namespace std;
int diff(int a, int b){
    if (a < b) {
        return b - a;
    }
    return a - b;
}
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            sum += diff(A[j], X);
        }
        cout << sum << endl;
    }
    return 0;
}