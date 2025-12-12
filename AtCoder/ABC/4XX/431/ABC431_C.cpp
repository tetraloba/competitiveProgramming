// 2025/12/12 20:45:08
// 2025/12/12 20:55:41
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> H(N), B(M);
    for (auto &h : H) {
        cin >> h;
    }
    for (auto &b : B) {
        cin >> b;
    }

    sort(H.begin(), H.end());
    sort(B.begin(), B.end());

    int cnt = 0;
    auto itr_h = H.begin();
    for (int b : B) {
        if (itr_h == H.end()) {
            break;
        }
        if (b < *itr_h) {
            continue;
        }
        cnt++;
        itr_h++;
    }

    cout << (K <= cnt ? "Yes" : "No") << endl;
    return 0;
}
