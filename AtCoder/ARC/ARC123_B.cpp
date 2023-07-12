// 2023/07/12 20:30:15
// 2023/07/12 20:37:32 WA
// 2023/07/12 20:39:59 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    bool flag = false;
    int ans = 0;
    int i = 0, j = 0, k = 0;
    for (; i < N; i++) {
        for (; j < N; j++) {
            if (A[i] < B[j]) {
                for (; k < N; k++) {
                    if (B[j] < C[k]) {
                        ans++;
                        k++;
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                j++;
                break;
            }
        }
        flag = false;
    }    
    cout << ans << endl;
    return 0;
}