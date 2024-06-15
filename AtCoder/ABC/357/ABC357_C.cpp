// 2024/06/15 16:02:44
// 2024/06/15 16:16:59 AC.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int size = pow(3, N);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int seg_i = i, seg_j = j, seg = size;
            bool done = false;
            while (3 <= seg) {
                if (seg / 3 <= seg_i && seg_i < seg / 3 * 2) {
                    if (seg / 3 <= seg_j && seg_j < seg / 3 * 2) {
                        cout << '.';
                        done = true;
                        break;
                    }
                }
                seg /= 3;
                seg_i %= seg;
                seg_j %= seg;
            }
            if (!done) {
                cout << '#';
            }
        }
        cout << endl;
    }
    return 0;
}
