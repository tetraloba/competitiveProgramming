//2022/08/20 07:54:32
//2022/08/20 07:58:38 AC.
//ABC003_C - AtCoderプログラミング講座
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }
    sort(R.begin(), R.end());
    double rate = 0;
    for (int i = N - K; i < N; i++) {
        // cout << R[i] << (i != N - 1 ? ' ' : '\n');
        rate = (rate + R[i]) / 2;
    }
    cout << fixed << rate << endl;
    return 0;
}