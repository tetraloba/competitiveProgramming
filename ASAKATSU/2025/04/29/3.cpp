// 2025/04/29 07:35:08
// 2025/04/29 07:42:21 AC.
// ABC264_D - "redocta".swap(i,i+1)
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    string S;
    cin >> S;
    map<char, int> mp = {{'a', 0}, {'t', 1}, {'c', 2}, {'o', 3}, {'d', 4}, {'e', 5}, {'r', 6}};
    vector<int> v;
    for (int i = 0; i < S.size(); i++) {
        v.push_back(mp[S[i]]);
    }
    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = i + 1; j < S.size(); j++) {
            if (v[j] < v[i]) {
                swap(v[i], v[j]);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
転倒数だが、やり方知らないのでバブルソートする。(2025/04/29 07:35:42)
*/
