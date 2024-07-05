#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    const int N = 4;
    while (true) {
        bool finish = true;
        vector<int> A(N);
        for (int &a : A) {
            cin >> a;
            if (a) finish = false;
        }
        if (finish) {
            return 0;
        }

        while (true) {
            int min = 101, min_i = -1;
            int cnt0 = 0;

            // for (int a : A) {
            //     cout << a << ' ';
            // }
            // cout << endl;
            for (int i = 0; i < N; i++) {
                if (!A[i]) {
                    cnt0++;
                    continue;
                }
                if (A[i] < min) {
                    min = A[i];
                    min_i = i;
                }
            }
            // cout << min_i << ':' << min << endl;
            if (cnt0 == N - 1) {
                break;
            }
            for (int i = 0; i < N; i++) {
                if (i == min_i) {
                    continue;
                }
                A[i] = max(0, A[i] - min);
            }
        }
        for (int a : A) {
            if (a) {
                cout << a << endl;
                break;
            }
        }
    }
}
/*
0 21 7 35
0 14 7 28
0 7 7 21
0 7 0 14
0 7 0 7
0 7 0 0

いや4つで100までって成約ゆるゆるやしシミュレーションすればよいか。(2024/07/05 14:41:27)

*/
