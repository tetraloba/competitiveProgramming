// 2025/01/01 15:36:20
// 2025/01/01 16:13:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> anss;

    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = 1 + i * 10;
    }

    while (true) {
        anss.push_back(ans);
        int i = N - 1;
        while (ans[i] < M) {
            ans[i]++;
            anss.push_back(ans);
        }
        while (true) {
            while (0 <= i && M <= ans[i]) {
                i--;
            }
            if (i < 0) {
                cout << anss.size() << '\n';
                for (auto an : anss) {
                    for (int a : an) {
                        cout << a << ' ';
                    }
                    cout << '\n';
                }
                return 0;
            }
            ans[i]++;
            int j = i + 1;
            while (j < N) {
                ans[j] = ans[j - 1] + 10;
                j++;
            }
            if (ans[N - 1] <= M) {
                break;
            }
        }
    }
}
