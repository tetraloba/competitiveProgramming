//2023/05/06 09:01:46
//2023/05/06 09:13:59 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) {
                cout << (char)(tmp + 'A' - 1);
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}