//2022/08/15 17:54:06
//2022/08/15 18:00:48 TLEじゃね？わからん。
//2022/08/15 18:28:17 TLE 知ってた
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        int tmp;
        for (int j = 0; j < L[i]; j++) {
            cin >> tmp;
            A[i].insert(A[i].end(), tmp);
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (L[i] == L[j]) {
                bool flag = true;
                for (int k = 0; k < L[i]; k++) {
                    // cout << A[i][k] << ':' << A[j][k] << endl;
                    if (A[i][k] != A[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
        }
    }

    cout << N - cnt << endl;
    return 0;
}