//2023/05/06 09:14:10
//2023/05/06 09:18:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> strs(H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int tmp;
            cin >> tmp;
            strs[i] += (tmp ? (char)(tmp + 'A' - 1) : '.');
        }
    }
    for (string s : strs) {
        cout << s << endl;
    }
    return 0;
}