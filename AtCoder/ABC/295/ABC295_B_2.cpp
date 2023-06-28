// 2023/06/28 10:12:51
// 2023/06/28 10:33:32 AC.
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
bool isBom(vector<string>& B, int i, int j){
    return B[i][j] != '.' && B[i][j] != '#';
}
int abs(int a, int b){
    return a < b ? b - a : a - b;
}
int mrange(int x1, int y1, int x2, int y2){
    return abs(x1, x2) + abs(y1, y2);
}
void bomb(vector<string>& B, int i, int j, int r, int R, int C){
    for (int k = 0; k < R; k++) {
        for (int l = 0; l < C; l++) {
            if (!isBom(B, k, l) && mrange(i, j, k, l) <= r) {
                B[k][l] = '.';
            }
        }
    }
    B[i][j] = '.';
}

int main(){
    int R, C;
    cin >> R >> C;
    vector<string> B(R);
    for (int i = 0; i < R; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (isBom(B, i, j)) {
                bomb(B, i, j, B[i][j] - '0', R, C);
            }
        }
    }

    for (string str : B) {
        cout << str << endl;
    }
    return 0;
}