// 2023/07/12 21:00:22
// 2023/07/12 21:08:40 WA
// 2023/07/12 21:16:37 WA
// 2023/07/12 21:17:52 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N, -1);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        if (A[s - 1] == -1 || A[s - 1] == c) {
            A[s - 1] = c;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    if (A[0] == 0) {
        if (N == 1) {
            cout << 0 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    if (A[0] == -1) {
        if (N == 1) {
            A[0] = 0;
        } else {
            A[0] = 1; 
        }
    }
    for (int i : A) {
        if (i == -1) {
            cout << 0;
        } else {
            cout << i;
        }
    }
    cout << endl;
    return 0;
}