//2022/08/04 17:51:21
//2022/08/04 18:09:50 AC.
#include <iostream>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    bool s[100][100] = {0};
    int U, V;
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        s[U - 1][V - 1] = true;
        s[V - 1][U - 1] = true;
    }
    // for (int i = 0; i < M - 1; i++) {
    //     for (int j = 0; j < M - 1; j++) {
    //         cout << s[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (s[i][j]) {
                for (int k = j + 1; k < N; k++) {
                    if (s[i][k] && s[j][k]) {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}