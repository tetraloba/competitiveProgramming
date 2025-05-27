// 2023/11/03 12:40:13
// 2023/11/03 12:41:40 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        if (C[i] == A + B) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}