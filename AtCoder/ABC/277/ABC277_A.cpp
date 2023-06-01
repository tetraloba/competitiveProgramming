//2023/02/16 15:11:23
//2023/02/16 15:14:15 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> P(N);
    int ans;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        if (P[i] == X) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}