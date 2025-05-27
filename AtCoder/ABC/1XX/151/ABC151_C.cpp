//2022/08/19 09:31:34
//2022/08/19 09:40:50 AC. ACとWAの初期化忘れてたよ…初歩的なミスに注意。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M, AC = 0, WA = 0;
    bool flgAC[100000] = {false};
    int cntWA[100000] = {0};
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int p;
        string S;
        cin >> p >> S;
        if (S[0] == 'A') {
            if (!flgAC[p - 1]) {
                WA += cntWA[p - 1];
                flgAC[p - 1] = true;
                AC++;
            }
        } else {
            cntWA[p - 1]++;
        }
    }
    cout << AC << ' ' << WA << endl;
    return 0;
}