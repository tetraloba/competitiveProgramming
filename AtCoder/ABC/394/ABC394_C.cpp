// 2025/02/26 20:09:43
// 2025/02/26 20:15:58 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    for (int i = S.size() - 2; 0 <= i; i--) {
        if (S[i] == 'W' && S[i + 1] == 'A') {
            S[i] = 'A';
            S[i + 1] = 'C';
        }
    }
    cout << S << endl;
    return 0;
}
/*
普通に左からやるとWWAが無理なわけか。(2025/02/26 20:15:03)
実は右からやるのが正解とか？(2025/02/26 20:15:12)
*/

