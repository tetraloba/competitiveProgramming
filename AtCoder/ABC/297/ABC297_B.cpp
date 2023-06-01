// 2023/06/01 19:40:28
// 2023/06/01 19:48:02 AC. なかなかに酷いプログラムを書いたものだ(笑)
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int posB1, posB2;
    int i = 0;
    while (i < S.size()) {
        if (S[i] == 'B') {
            posB1 = i;
            i++;
            break;
        }
        i++;
    }
    while (i < S.size()) {
        if (S[i] == 'B') {
            posB2 = i;
            break;
        }
        i++;
    }
    if ((posB1 + posB2) % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    i = 0;
    while (i < S.size()) {
        if (S[i] == 'R') {
            i++;
            break;
        }
        i++;
    }
    while (i < S.size()) {
        if (S[i] == 'R') {
            cout << "No" << endl;
            return 0;
        }
        if (S[i] == 'K') {
            cout << "Yes" << endl;
            return 0;
        }
        i++;
    }
    return 0;
}