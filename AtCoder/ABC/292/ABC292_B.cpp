//2023/04/05 23:02:46
//2023/04/05 23:08:15 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> player(N + 1, 0);
    for (int i = 0; i < Q; i++) {
        int c, x;
        cin >> c >> x;
        switch (c) {
          case 1:
            player[x]++;
            break;
          case 2:
            player[x] = player[x] + 2;
            break;
          case 3:
            if (2 <= player[x]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            break;
        }
    }
    return 0;
}