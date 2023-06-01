//2022/08/13 17:10:10
//2022/08/13 17:14:13 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(9);
    for (int i = 0; i < N; i++) {
        cnt[A[i] - 1]++;
    }
    int max_i = 0;
    for (int i = 1; i < 9; i++) {
        if (cnt[max_i] < cnt[i]) {
            max_i = i;
        }
    }
    cout << max_i + 1 << endl;
    return 0;
}