// 2024/11/30 11:56:22
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int &h : H) {
        cin >> h;
    }
    long long T = 0;
    for (int i = 0; i < N; i++) {
        cout << i << ' ' << T << endl;
        while (0 < H[i]) {
            T++;
            if (T % 3) {
                H[i]--;
            } else {
                H[i] -= 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}
/*
テストケース生成用に。愚直にシミュレーション
9
1 12 123 1234 12345 123456 1234567 12345678 123456789
0 0
1 1
2 9
3 84
4 825
5 8232
6 82306
7 823047
8 8230455
82304529



*/
