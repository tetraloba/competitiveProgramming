// CODE FESTIVAL 2017 Final A - AKIBA
// 2024/12/09 07:36:37
// 2024/12/09 07:55:56 AC.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string S;
    cin >> S;
    string T = "AKIHABARA";
    vector<int> Aindex = {0, 4, 6, 8};
    int C = 1 << Aindex.size();
    for (int c = 0; c < C; c++) {
        string T2 = T;
        for (int i = 0; i < Aindex.size(); i++) {
            if ((c >> i) & 1) {
                continue;
            }
            T2[Aindex[i]] = '*';
        }
        T2.erase(remove(T2.begin(), T2.end(), '*'), T2.end());
        if (S == T2) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
