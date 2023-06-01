//2022/08/22 07:57:32
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    bool flag = true;
    int fnni = N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        if (!x[i]) {
            N--;
            K--;
        }
        if (0 < x[i] && flag) {
            fnni = i; //first natural-number index
            flag = false;
        }
    }
    vector<int> sumP(N - fnni), sumN(fnni);
    for (int i = fnni; i < N; i++) {
        sumP[i - fnni] = x[i] + (i != fnni ? sumP[i - fnni - 1] : 0);
    }
    for (int i = fnni - 1; 0 <= i; i--) {
        sumN[fnni - 1 - i] = (x[i] + (i != fnni - 1 ? -sumN[fnni - 1 - i - 1] : 0)) * -1;
    }
    for (int i : sumP) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : sumN) {
        cout << i << ' ';
    }
    cout << endl;

    for () //非負側の数基準で探索～
    return 0;
}
//非負K本から0以下K本までのK通り。