// 2025/04/28 21:47:04
// 2025/04/28 21:55:09 4WA
// 2025/04/28 21:58:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    const vector<char> keys = {'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
    const vector<string> tones = {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "So", "So#", "La", "La#", "Si"};
    string S;
    cin >> S;
    for (int i = 0; i < 12; i++) {
        bool flag = true;
        for (int j = 0; j < 20; j++) {
            if (keys[i + j] != S[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << tones[i] << endl;
            return 0;
        }
    }
    return 0;
}
/*
WBWBWWBWBWBW WBWBWWBW
*/
