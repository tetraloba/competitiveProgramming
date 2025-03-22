// 2025/03/22 21:10:17
// 2025/03/22 21:17:51 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    map<int, int> cnt;
    for (int a : A) {
        cnt[a]++;
    }
    int max_num = 0;
    for (auto itr = cnt.rbegin(); itr != cnt.rend(); itr++) {
        // cerr << itr->first << ',' << itr->second << endl;
        if (2 <= itr->second) {
            continue;
        }
        max_num = itr->first;
        break;
    }
    if (max_num == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == max_num) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}
