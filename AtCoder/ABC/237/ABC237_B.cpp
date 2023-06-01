//2022/08/15 19:57:27
//2022/08/15 20:01:56 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H); 
    for (int i = 0; i < H; i++) {
        vector<int> tmp(W);
        for (int j = 0; j < W; j++) {
            cin >> tmp[j];
        }
        A[i] = tmp;
    }
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cout << A[j][i] << (j != H - 1 ? ' ' : '\n');
        }
    }
    return 0;
}