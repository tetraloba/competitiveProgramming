//2022/08/21 07:30:07
//2022/08/21 07:34:37 AC.
//ABC241_C - Inverse of Permutation
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> p(N), q(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < N; i++) {
        q[p[i]- 1] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << q[i] << (i != N - 1 ? ' ' : '\n');
    }
    return 0;
}