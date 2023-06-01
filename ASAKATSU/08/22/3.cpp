//2022/08/22 07:45:49
//2022/08/22 07:52:00 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int N = s.size();
    for (auto itr = s.begin(); itr != s.end();) {
        if (*itr == 'B') {
            s.erase(itr);
            if (itr != s.begin()) {
                itr--;
                s.erase(itr);
            }
        } else {
            itr++;
        }
    }
    cout << s << endl;
    return 0;
}