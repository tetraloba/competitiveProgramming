// 2024/04/03 07:41:51
// 2024/04/03 07:49:47 AC.
// ABC098_B - Cut and Count
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int max = 0;
    for (int j = 1; j < N; j++) {
        set<int> L, R, inter;
        int i = 0;
        while (i < j) {
            L.insert(S[i]);
            i++;
        }
        while (i < N) {
            R.insert(S[i]);
            i++;
        }
        set_intersection(L.begin(), L.end(), R.begin(), R.end(), inserter(inter, inter.end()));
        if (max < inter.size()) {
            max = inter.size();
        }
    }
    cout << max << endl;
    return 0;
}
/*
高速化する必要なし？
*/
