// 2023/06/06 23:13:41
// 2023/06/06 23:16:47 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> T[i];
    }
    int i = 0, j = 0;
    while (i < N) {
        if (S[i] == T[j]) {
            cout << "Yes" << endl;
            i++;
            j++;
        } else {
            cout << "No" << endl;
            i++;
        }
    }
    return 0;
}