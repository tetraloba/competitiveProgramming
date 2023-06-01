//2022/08/13 17:06:20
//2022/08/13 17:09:05 AC.
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
    unsigned int flags[9] = {0};
    for (int i = 0; i < N; i++) {
        flags[A[i] - 1]++;
    }
    for (int i = 0; i < 9; i++) {
        cout << flags[i] << endl;
    }
    return 0;
}