// 2023/05/15 12:40:35
// 2023/05/15 12:45:06 マンハッタン距離のやり方が分からない。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int R, C;
    cin >> R >> C;
    vector<vector<char>> B(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ('1' <= B[i][j] && B[i][j] <= '9') {
                ;
            }
        }
    }
    cout <<  << endl;
    return 0;
}