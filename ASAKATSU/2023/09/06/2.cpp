// 2023/09/06 07:31:59
// 2023/09/06 07:58:39 AC.
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b){
    return a < b ? b : a;
}
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int N;
    cin >> N;
    vector<int> F(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
    }
    int maxS_i = 0;
    for (int i = 0; i < N; i++) {
        if (S[maxS_i] < S[i]) {
            maxS_i = i;
        }
    }
    int ans = 0, tmp;
    for (int i = 0; i < N; i++) {
        if (i == maxS_i) {
            continue;
        }
        if (F[i] == F[maxS_i]) {
            tmp = max(S[i], S[maxS_i]) + min(S[i], S[maxS_i]) / 2;
        } else {
            tmp = S[i] + S[maxS_i];
        }
        if (ans < tmp) {
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}