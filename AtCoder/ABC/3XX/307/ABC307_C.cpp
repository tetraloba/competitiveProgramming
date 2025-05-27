// 2023/11/05 12:23:00
// 
#include <iostream>
#include <vector>
using namespace std;
char req(char in, char res) {
    if (in == '.' && res == '#') {
        return '#';
    }
    if (in == '.' && res == '.') {
        return '.';
    }
    if (in == '#' && res == '#') {
        return '-';
    }
    // if (in == '#' && res == '.') {
    //     return '!';
    // }
    return '!';
}
int main(){
    int HA, WA, HB, WB, HX, WX;
    cin >> HA >> WA;
    vector<string> A(HA);
    for (int i = 0; i < HA; i++) {
        cin >> A[i];
    }
    cin >> HB >> WB;
    vector<string> B(HB);
    for (int i = 0; i < HB; i++) {
        cin >> B[i];
    }
    cin >> HX >> WX;
    vector<string> X(HX);
    for (int i = 0; i < HX; i++) {
        cin >> X[i];
    }


    pair<int, int> ltX(-1, -1);
    for (int i = 0; i < HX; i++) {
        for (int j = 0; j < WX; j++) {
            if (X[i][j] == '#') {
                ltX = make_pair(i, j);
                break;
            }
        }
        if (ltX.first != -1) {
            break;
        }
    }

    /* ltX が A 由来の # の時 */
    pair<int, int> ltA(-1, -1);
    for (int i = 0; i < HA; i++) {
        for (int j = 0; j < WA; j++) {
            if (A[i][j] == '#') {
                ltA = make_pair(i, j);
                break;
            }
        }
        if (ltA.first != -1) {
            break;
        }
    }
    vector<vector<char>> B_req(HB, vector<char>(WB, '!'));
    for (int i = 0; i < HB; i++) {
        for (int j = 0; j < WB; j++) {
            B_req[i][j] = req(A[ltA.first + i][ltA.second + j], X[ltX.first + i][ltX.second + j]);
        }
    }

    /* debug */
    for (int i = 0; i < HB; i++) {
        for (int j = 0; j < WB; j++) {
            cout << B_req
        }
    }
    cout <<  << endl;
    return 0;
}
// Xの最も左上の#がAかBか両方かを確かめる
// Aで決めた時、Aの左上で合わせて、Bとしてあり得るシートの条件(#,.,-)を決める
// Bも同様
// A,B両方の場合は1択検証するだけ
