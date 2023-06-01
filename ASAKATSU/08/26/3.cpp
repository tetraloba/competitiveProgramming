//2022/08/26 07:41:43
//2022/08/26 07:53:54 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M, L, P, Q, R;
    cin >> N >> M >> L >> P >> Q >> R;
    vector<int> arr(6);
    arr[0] = (N / P) * (M / Q) * (L / R);
    arr[1] = (N / P) * (M / R) * (L / Q);
    arr[2] = (N / Q) * (M / P) * (L / R);
    arr[3] = (N / Q) * (M / R) * (L / P);
    arr[4] = (N / R) * (M / P) * (L / Q);
    arr[5] = (N / R) * (M / Q) * (L / P);
    cout << *max_element(arr.begin(), arr.end()) << endl;
    return 0;
}