// 2023/06/06 23:09:49
// 2023/06/06 23:13:23 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N + 1, 4);
    for (int i = 1; i <= 4 * N - 1; i++) {
        int tmp;
        cin >> tmp;
        A[tmp]--;
    }
    for (int i = 1; i <= N; i++) {
        if (A[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}