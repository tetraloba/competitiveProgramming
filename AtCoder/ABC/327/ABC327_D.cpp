// 2023/11/04 21:14:17
// 2023/11/04 21:35:13 TLE WA
// 2023/11/04 21:47:50 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool func(vector<int>& X, vector<set<int>>& stv, vector<bool>& done, int i){
    if (done[i]) {
        return true;
    }
    done[i] = true;
    for (int s : stv[i]) {
        if (X[s] == -1) {
            X[s] = X[i] == 1 ? 0 : 1;
        } else if (X[s] == X[i]) {
            return false;
        }
        if (!func(X, stv, done, s)) {
            return false;
        }
    }
    return true;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<set<int>> stv(N + 1);
    for (int i = 0; i < M; i++) {
        stv[A[i]].insert(B[i]);
        stv[B[i]].insert(A[i]);
    }

    vector<int> X(N + 1, -1);
    vector<bool> done(N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (!done[i]) {
            X[i] = 0;
            if (!func(X, stv, done, i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}