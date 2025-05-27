//2023/01/08 11:13:26
//2023/01/08 12:00:01 WA.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = N - 1; i; i--) {
        if (v[i] < v[i - 1]) {
            // swap(v[i - 1], v[distance(v.begin(), max_element(v.begin() + i, v.end()))]);
            swap(v[i - 1], v[distance(v.begin(), find(v.begin() + i, v.end(), v[i - 1] - 1))]);
            sort(v.rbegin(), v.rend() - i);
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
// 1 4 2 3
// 1 4 3 2
// 2 1 3 4
// 2 1 4 3
// 2 3 1 4
// 2 3 4 1

// 2 4 1 3
// 2 4 3 1
// 3 1 2 4
// 3 1 4 2
// 3 2 1 4
// 3 2 4 1
// 3 4 1 2
// 3 4 2 1
// 4 1 2 3

//3 1 2 4 7