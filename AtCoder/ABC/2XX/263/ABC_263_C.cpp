//2022/08/06 21:20:47
//
#include <iostream>
using namespace std;
int main(){
    int N, M, arr[10];
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
        }
        while (1) {
            for (int j = 0; j < i; j++) {
                arr[N - 1 - j]++;
            }
            if (arr[N - 1] <= M) {
                for (int k = 0; k < N; k++) {
                    cout << arr[k];
                    if (k < N - 1) {
                        cout << ' ';
                    } else {
                        cout << endl;
                    }
                }
            } else {
                break;
            }
        }
    }
    return 0;
}