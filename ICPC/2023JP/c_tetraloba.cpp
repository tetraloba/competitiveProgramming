#include <iostream>
#include <vector>
using namespace std;
int main(){
    while (true) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        vector<vector<int>> vv1(n, vector<int>(n));
        vector<vector<int>> vv2(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vv1[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vv2[i][j] = vv1[i][(j * 2 + 1) % (n + (n + 1) % 2)];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                vv1[i][j] = vv2[(i * 2 + 1) % (n + (n + 1) % 2)][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << vv1[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}