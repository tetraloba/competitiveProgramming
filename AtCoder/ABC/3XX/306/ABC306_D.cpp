// 2024/07/29 20:59:44
// 2024/07/29 21:22:23 AC.
#include <iostream>
#include <vector>
using namespace std;
struct Takahashi{
    bool poison;
    int value;
};
int main(){
    int N;
    cin >> N;
    vector<Takahashi> XY(N);
    for (Takahashi &xy : XY) {
        cin >> xy.poison >> xy.value;
    }
    long long max_with_poison = 0, max_without_poison = 0;
    for (Takahashi xy : XY) {
        if (xy.poison) {
            max_with_poison = max(max_without_poison + xy.value, max_with_poison);
        } else {
            max_without_poison = max(max(max_with_poison + xy.value, max_without_poison + xy.value), max_without_poison);
        }
    }
    cout << max(max_with_poison, max_without_poison) << endl;
    return 0;
}
/*
動的計画法(DP)の問題であることまでは分かっているんだが、DPらしく解けていないのが残念だな。
DP[][]を作りたい。(2024/07/29 21:38:15)
*/
