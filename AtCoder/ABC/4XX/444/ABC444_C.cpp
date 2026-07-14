// 2026/07/14 11:23:02
// 2026/07/14 11:41:46 AC.
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool solve(const vector<int>& A, const int L) {
    map<int, int> counter;
    for (int a : A) {
        counter[a]++;
    }
    int remain = A.size() - counter[L];
    if (remain % 2 != 0) {
        return false;
    }
    for (auto itr = counter.begin(); itr != counter.end(); itr++) {
        if (itr->first == L) {
            continue;
        }
        if (L < itr->first) {
            return false;
        }
        if (itr->second != counter[L - itr->first]) {
            return false;
        }
    }
    return true;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    
    sort(A.begin(), A.end());
    vector<int> candidate = {A.back(), A.back() + A.front()};
    vector<int> ans;
    for (int c : candidate) {
        if (solve(A, c)) {
            ans.push_back(c);
        }
    }
    for (int a : ans) {
        cout << a << ' ';
    }
    cout << endl;
    return 0;
}
/*
Lの最小値はa(∈A)の最大値
Lの最大値はaの最大値と最小値の和？
2026/07/14 11:30:41
それ以外を思いつかないのだが。
*/
