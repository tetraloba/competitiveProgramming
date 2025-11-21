// 2025/11/21 21:36:40
// 2025/11/21 21:49:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n));
    int value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            vv[j][i - j] = value;
            value++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
