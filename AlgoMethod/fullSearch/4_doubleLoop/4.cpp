//2022/08/15 13:25:33
//2022/08/15 13:27:42 AC.
#include <iostream>
#include <set>
using namespace std;
int main(){
    string S;
    cin >> S;
    set<int> s;
    for (int i = 0; S[i]; i++) {
        s.insert(S[i]);
    }
    cout << s.size() << endl;
    return 0;
}