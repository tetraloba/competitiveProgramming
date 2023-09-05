// 2023/09/06 07:40:44
// 2023/09/06 07:49:24
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < t[i]) {
            cout << "Yes" << endl;
            return 0;
        }
        if (t[i] < s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << (s.size() < t.size() ? "Yes" : "No") << endl;
    return 0;
}