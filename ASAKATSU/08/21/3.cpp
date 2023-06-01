//2022/08/21 07:43:31
//2022/08/21 07:48:03 AC.
//ABC082_B - Two Anagrams
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.rbegin(), t.rend());
    // cout << s << ' ' << t << endl; //debug
    cout << (s < t ? "Yes" : "No") << endl;
    return 0;
}