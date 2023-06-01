//2022/08/21 16:11:17
//2022/08/21 16:14:42 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (T[i] == S[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}