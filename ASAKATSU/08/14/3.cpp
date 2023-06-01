//2022/08/14 07:38:32
//愚直にシミュレーションすると余裕でTLE
#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    vector<long long> A(5);
    cin >> N >> A[0] >> A[1] >> A[2] >> A[3] >> A[4];
    vector<long long> arr(6);
    arr[0] = N;
    long long t = 0;
    for (; arr[5] != N; t++) {
        cout << "t:" << t << ' ';
        for (int i = 4; 0 <= i; i--) {
            long long tP = (A[i] <= arr[i] ? A[i] : arr[i]);
            arr[i] -= tP;
            arr[i + 1] += tP;
        }
        for (int j = 0; j < 6; j++) {
            cout << arr[j] << ' ';
        }
        cout << endl;
    }
    cout << t << endl;
    return 0;
}