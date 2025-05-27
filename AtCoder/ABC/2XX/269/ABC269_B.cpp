// 2023/06/03 11:16:21
// 2023/06/03 11:31:45 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S[11];
    for (int i = 1; i <= 10; i++) {
        string tmp;
        cin >> tmp;
        S[i] = ' ' + tmp;
    }

    pair<int, int> tl, br = make_pair(10, 10);
    bool flag = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (flag && S[i][j] == '#') {
                tl = make_pair(i, j);
                flag = false;
            }
        }
    }
    for (int i = tl.first + 1; i <= 10; i++) {
        if (S[i][tl.second] == '.') {
            br.first = i - 1;
            break;
        }
    }
    for (int i = tl.second + 1; i <= 10; i++) {
        if (S[tl.first][i] == '.') {
            br.second = i - 1;
            break;
        }
    }
    cout << tl.first << ' ' << br.first << '\n' << tl.second << ' ' << br.second << endl;
    return 0;
}